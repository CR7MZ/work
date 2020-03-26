//题目：https://leetcode-cn.com/problems/range-sum-query-immutable/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//思路:因为题中说明会调用很多次sumRange，所以每次用逐个相加是不可行的。
//因此实用动态规划，建立一个数组dp，数组中第i个位置中保存的是nums中前i个数(包括位置i)的和。
//当我们想要知道区间[i,j]的和，就可以直接用dp中下标j位置存储的值(nums中前j个元素的和)-下标i位置存储的值（nums中前i个元素的和）
class NumArray {
public:
	NumArray(vector<int>& nums) {
		int num = nums.size();
		dp.resize(num + 1, 0);
		for (int i = 1; i <= num; i++){
			dp[i] = dp[i - 1] + nums[i - 1];
		}
	}

	int sumRange(int i, int j) {
		return dp[j + 1] - dp[i];
	}
private:
	vector<int> dp;
};