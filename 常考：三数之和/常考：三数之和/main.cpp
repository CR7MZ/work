#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//题目：https://leetcode-cn.com/problems/3sum/
//解析：因为三个数相加要得到0，所以先排序，挨个锁定一个数，改变后面两个数的索引，找符合条件的数值。

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int target;
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;       //题目要求不需要重复
			target = nums[i];                                       
			if (target > 0) break;                               //若target为正数，那么后面全部为正数，因此不存在三数相加为0
			int l = i + 1, r = nums.size() - 1;
			while (l < r) {
				if (nums[l] + nums[r] + target < 0) ++l;
				else if (nums[l] + nums[r] + target > 0) --r;
				else {
					ans.push_back({ target, nums[l], nums[r] });
					++l, --r;
					while (l < r && nums[l] == nums[l - 1]) ++l;
					while (l < r && nums[r] == nums[r + 1]) --r;
				}
			}
		}
		return ans;
	}
};