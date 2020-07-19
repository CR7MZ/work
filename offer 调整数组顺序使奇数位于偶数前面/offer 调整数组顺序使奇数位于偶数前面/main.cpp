//题目：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/submissions/
#include<iostream>
#include<vector>
//思路：定义两个指针i,j，分别从头和尾开始遍历，i遇见偶数停下，j遇见奇数停下，交换i,j指向的值
vector<int> exchange(vector<int>& nums) {
	int i = 0, j = nums.size() - 1;
	while (i < j){
		while (i <= j && nums[i] % 2 == 1){
			++i;
		}
		while (i <= j && nums[j] % 2 == 0){
			--j;
		}
		if (i < j){
			swap(nums[i], nums[j]);
		}
	}
	return nums;
}