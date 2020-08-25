#include <iostream>
#include <vector>
using namespace std;

//题目：森林中有N棵树，指向某一棵树那么该树不生长(仅此次指向不生长)，其他树长1。问最少指向几次才可以使森林中的树高度平衡。

//给其他树+1，可以认为给指向的树-1，因此计算所有树木高度与森林中最小高度的差值之和。即可。

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int min = INT_MAX;
		for (int i = 0; i<nums.size(); i++){
			if (min > nums[i]){
				min = nums[i];
			}
		}

		int res = 0;
		for (int i = 0; i<nums.size(); i++){
			res += nums[i] - min;
		}
		return res;
	}
};