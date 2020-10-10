#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��Ŀ��https://leetcode-cn.com/problems/3sum/
//��������Ϊ���������Ҫ�õ�0�����������򣬰�������һ�������ı�������������������ҷ�����������ֵ��

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int target;
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;       //��ĿҪ����Ҫ�ظ�
			target = nums[i];                                       
			if (target > 0) break;                               //��targetΪ��������ô����ȫ��Ϊ��������˲������������Ϊ0
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