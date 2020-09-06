#include <iostream>
#include <vector>
using namespace std;
//��Ŀ��https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/

//��������Ϊ1 �� a[i] �� n �������������������������±��1�����ǿ��԰�����ֵ�����±����������飬��ô��ͬ��ֵ��Ϊ
//		�±�ָ���ֵ�϶��������Ρ����ֻ��Ҫ����������������֮�󣬿����жϳ��ĸ�Ԫ�ر������˶�εķ������ɣ���Ϊ
//		1 �� a[i] �� n����������ÿ����һ��Ԫ�ظ���+n��������������֮�������ٴα�������ʱ�����ĳ��Ԫ�ش���2n����ô
//		�������ε�Ԫ�ؾ�Ϊ��ǰԪ�ص��±�+1��

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

//��λ���������������ֶ���λ��������ظ�һ������nums[i] = nums[nums[i]]�����ظ�����λnums[i]��

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