//题目：https://leetcode-cn.com/problems/third-maximum-number/submissions/

//定义三个长整型变量，来保存第一大、第二大、第三大的值。每个值初始化为长整型的下限LONG_MIN。（之所以不用整形来定义，是因为可能出现溢出，所以用长整型long long占8个字节，64个比特位）
//遍历数组，找出三个最大的数分别保存在max1、max2、max3中，如果max3等于LONG_MIN说明没有第三大的值，返回最大的值max1，反之返回max3.
#include<iostream>
#include<vector>
int thirdMax(std::vector<int>& nums)
{
	int max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
	for (size_t i = 0; i<nums.size(); i++)
	{
		if (nums[i]>max1)//之前的值整体往后降级，将比max1大的值，赋给max1。
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