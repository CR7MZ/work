//题目：https://leetcode-cn.com/problems/house-robber/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//思路：
//对于这种求极值首先考虑动态规划，维护一个数字dp，其中dp用来保存[0,i]区间的最大值对当前i来说，有抢和不抢两种互斥的选择，
//不抢即为 dp[i-1]（等价于去掉 nums[i] 只抢 [0, i-1] 区间最大值），抢即为 dp[i-2] + nums[i]（等价于去掉 nums[i-1]）。

//再举一个简单的例子来说明一下吧，比如说 nums为{3, 2, 1, 5}，那么来看 dp 数组应该是什么样的，
//首先 dp[0]=3 没啥疑问，再看 dp[1] 是多少呢，由于3比2大，所以抢第一个房子的3，当前房子的2不抢，则dp[1]=3，
//那么再来看 dp[2]，由于不能抢相邻的，所以可以用再前面的一个的 dp 值加上当前的房间值，和当前房间的前面一个 dp 值比较，
//取较大值当做当前 dp 值，这样就可以得到状态转移方程 dp[i] = max(num[i] + dp[i - 2], dp[i - 1]), 
//且需要初始化 dp[0] 和 dp[1]，其中 dp[0] 即为 num[0]，dp[1] 此时应该为 max(num[0], num[1]).

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)return 0;
		if (nums.size() == 1)return nums[0];
		if (nums.size() == 2) return max(nums[0], nums[1]);
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i<nums.size(); i++)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[nums.size() - 1];
	}
};