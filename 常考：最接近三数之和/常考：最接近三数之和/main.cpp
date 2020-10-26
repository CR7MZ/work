#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��Ŀ��https://leetcode-cn.com/problems/3sum-closest/

int threeSumClosest(vector<int>& nums, int target) {
	int closenum = 999;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++){
		int index = nums[i];
		int left = i + 1, right = nums.size() - 1;
		while (left < right){
			int tmp = index + nums[left] + nums[right];
			if (abs(closenum - target) > abs(tmp - target)){   //�жϵ�ǰ�������ֺ��Ƿ��target���
				closenum = tmp;
			}
			if (tmp > target){
				right--;
			} else if (tmp < target){
				left++;
			} else {
				return target;                                //������֮��Ϊtarget����ô���ظ�����
			}
		}
	}
	return closenum;
}