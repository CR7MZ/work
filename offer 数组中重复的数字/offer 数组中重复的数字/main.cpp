//题目：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/comments/
#include<iostream>
#include<vector>

//采用数组哈希的方式，因为题目规定数字的范围是0~n-1
//因此定义一个size为nums.size（）的数组，模拟哈希的方式
//时间复杂度O(N)，空间复杂度O(N)
bool duplicate(int numbers[], int length, int* duplication) {
	vector<int> tmp(nums.size());
        for (int i = 0;i < nums.size();i++){
            tmp[nums[i]]++;
            if (tmp[nums[i]] > 1)
                return nums[i];
        }
	    return 0;
}