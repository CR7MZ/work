//题目：https://leetcode-cn.com/problems/find-pivot-index/comments/
#include<iostream>
#include<vector>
//借助于题目，我们可以只算出左边数的总和，然后乘2再加上中心索引，如果等于所有数之和，说明的得到中心索引。
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