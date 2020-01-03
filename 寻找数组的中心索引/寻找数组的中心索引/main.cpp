//��Ŀ��https://leetcode-cn.com/problems/find-pivot-index/comments/
#include<iostream>
#include<vector>
//��������Ŀ�����ǿ���ֻ�����������ܺͣ�Ȼ���2�ټ��������������������������֮�ͣ�˵���ĵõ�����������
int pivotIndex(std::vector<int>& nums)
{
	int sum = 0;
	int sumleft = 0;
	for (auto e : nums)
		sum += e;
	for (size_t i = 0; i < nums.size();i++)
	{
		if (sumleft * 2 + nums[i] == sum)
			return i;
		sumleft += nums[i];
	}
	return -1;
}