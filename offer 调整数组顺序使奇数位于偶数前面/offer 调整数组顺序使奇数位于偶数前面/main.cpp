//��Ŀ��https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/submissions/
#include<iostream>
#include<vector>
//˼·����������ָ��i,j���ֱ��ͷ��β��ʼ������i����ż��ͣ�£�j��������ͣ�£�����i,jָ���ֵ
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