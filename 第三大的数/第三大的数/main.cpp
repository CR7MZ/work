//��Ŀ��https://leetcode-cn.com/problems/third-maximum-number/submissions/

//�������������ͱ������������һ�󡢵ڶ��󡢵������ֵ��ÿ��ֵ��ʼ��Ϊ�����͵�����LONG_MIN����֮���Բ������������壬����Ϊ���ܳ�������������ó�����long longռ8���ֽڣ�64������λ��
//�������飬�ҳ������������ֱ𱣴���max1��max2��max3�У����max3����LONG_MIN˵��û�е������ֵ����������ֵmax1����֮����max3.
#include<iostream>
#include<vector>
int thirdMax(std::vector<int>& nums)
{
	int max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
	for (size_t i = 0; i<nums.size(); i++)
	{
		if (nums[i]>max1)//֮ǰ��ֵ�������󽵼�������max1���ֵ������max1��
		{
			max3 = max2;
			max2 = max1;
			max1 = nums[i];
		}
		else if (nums[i]<max1&&nums[i]>max2)
		{
			max3 = max2;
			max2 = nums[i];
		}
		else if (nums[i]<max2&&nums[i]>max3)
			max3 = nums[i];
	}
	if (max3 != LONG_MIN)
		return max3;
	else
		return max1;
}