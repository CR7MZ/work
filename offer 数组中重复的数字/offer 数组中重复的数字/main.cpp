//��Ŀ��https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/comments/
#include<iostream>
#include<vector>

//���������ϣ�ķ�ʽ����Ϊ��Ŀ�涨���ֵķ�Χ��0~n-1
//��˶���һ��sizeΪnums.size���������飬ģ���ϣ�ķ�ʽ
//ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(N)
bool duplicate(int numbers[], int length, int* duplication) {
	vector<int> tmp(nums.size());
        for (int i = 0;i < nums.size();i++){
            tmp[nums[i]]++;
            if (tmp[nums[i]] > 1)
                return nums[i];
        }
	    return 0;
}