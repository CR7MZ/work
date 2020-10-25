#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//题目：https://leetcode-cn.com/problems/4sum/
//解析：类似于三数之和，先固定其中一个值，之后则变为三数取中

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	if (nums.empty()) return{};

	for (int i = 0; i < nums.size(); i++){
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		int tmp = target - nums[i];
		for (int j = i + 1; j < nums.size(); j++){
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			int index = nums[j];
			int left = j + 1, right = nums.size() - 1;
			while (left < right){
				if 
					(index + nums[left] + nums[right] > tmp)right--;
				else if 
					(index + nums[left] + nums[right] < tmp) left++;
				else {
					res.push_back({ nums[i], index, nums[left], nums[right] });
					left++; right--;
					while (left < right && nums[left] == nums[left - 1])   
						left++;
					while (left < right && nums[right] == nums[right + 1])   
						right--;
				}
			}
		}
	}
	return res;
}