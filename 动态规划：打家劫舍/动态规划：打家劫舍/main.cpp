//��Ŀ��https://leetcode-cn.com/problems/house-robber/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//˼·��
//����������ֵ���ȿ��Ƕ�̬�滮��ά��һ������dp������dp��������[0,i]��������ֵ�Ե�ǰi��˵�������Ͳ������ֻ����ѡ��
//������Ϊ dp[i-1]���ȼ���ȥ�� nums[i] ֻ�� [0, i-1] �������ֵ��������Ϊ dp[i-2] + nums[i]���ȼ���ȥ�� nums[i-1]����

//�پ�һ���򵥵�������˵��һ�°ɣ�����˵ numsΪ{3, 2, 1, 5}����ô���� dp ����Ӧ����ʲô���ģ�
//���� dp[0]=3 ûɶ���ʣ��ٿ� dp[1] �Ƕ����أ�����3��2����������һ�����ӵ�3����ǰ���ӵ�2��������dp[1]=3��
//��ô������ dp[2]�����ڲ��������ڵģ����Կ�������ǰ���һ���� dp ֵ���ϵ�ǰ�ķ���ֵ���͵�ǰ�����ǰ��һ�� dp ֵ�Ƚϣ�
//ȡ�ϴ�ֵ������ǰ dp ֵ�������Ϳ��Եõ�״̬ת�Ʒ��� dp[i] = max(num[i] + dp[i - 2], dp[i - 1]), 
//����Ҫ��ʼ�� dp[0] �� dp[1]������ dp[0] ��Ϊ num[0]��dp[1] ��ʱӦ��Ϊ max(num[0], num[1]).

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