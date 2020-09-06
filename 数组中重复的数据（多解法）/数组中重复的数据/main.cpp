#include <iostream>
#include <vector>
using namespace std;
//题目：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/

//解析：因为1 ≤ a[i] ≤ n 这个条件，正好与我们数组的下标差1，我们可以按照数值当做下标来遍历数组，那么相同数值作为
//		下标指向的值肯定经过两次。因此只需要想出在这个遍历结束之后，可以判断出哪个元素被经过了多次的方法即可，因为
//		1 ≤ a[i] ≤ n，所以我们每经过一个元素给其+n，，当遍历结束之后，我们再次遍历数组时，如果某个元素大于2n，那么
//		出现两次的元素就为当前元素的下标+1。

vector<int> findDuplicates(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++){
		nums[(nums[i] - 1) % nums.size()] += nums.size();
	}

	int pre = 0;
	for (int i = 0; i < nums.size(); i++){
		if (nums[i] > 2 * nums.size()){
			nums[pre] = i + 1;
			pre++;
		}
	}
	int len = nums.size() - pre;
	while (len--){
		nums.pop_back();
	}
	return nums;
}

//归位方法：将所有数字都归位，如果有重复一定会有nums[i] = nums[nums[i]]，则重复的数位nums[i]。

int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size();i++){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
   }