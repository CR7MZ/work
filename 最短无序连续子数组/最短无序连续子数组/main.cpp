//��Ŀ��https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/submissions/

#include<iostream>
#include<vector>
//���¶���һ�����飬��ԭ�����Ԫ�ط��룬�������������򡣶�������ָ�룬��ԭ�����������ֱ��ǰ���ʹӺ���ǰ���бȽϣ�����Ԫ�ز���ȣ�
//��˵���˴���ʼ��ԭ�����в�������ġ�

int findUnsortedSubarray(std::vector<int>& nums) {
	std::vector<int> tmp(nums.begin(), nums.end());
	sort(tmp.begin(), tmp.end());
	int i = 0, j = nums.size() - 1;
	while (i<j)
	{
		int flag = 1;
		if (nums[i] == tmp[i])
		{
			i++;
			flag = 0;
		}
		if (nums[j] == tmp[j])
		{
			j--;
			flag = 0;
		}
		if (flag == 1)//˵����������ȫ���ҵ�
			break;
	}
	if (i >= j)//˵�� û��ԭ������û������������
	{
		return 0;
	}
	return j - i + 1;
}