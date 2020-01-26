//题目：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/submissions/

#include<iostream>
#include<vector>
//重新定义一个数组，将原数组的元素放入，并将新数组排序。定义两个指针，将原数组和新数组分别从前向后和从后向前进行比较，若有元素不相等，
//则说明此处开始在原数组中不是升序的。

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
		if (flag == 1)//说明两个坐标全部找到
			break;
	}
	if (i >= j)//说明 没有原数组中没有无序子数组
	{
		return 0;
	}
	return j - i + 1;
}