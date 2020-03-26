//��Ŀ��https://leetcode-cn.com/problems/range-sum-query-immutable/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//˼·:��Ϊ����˵������úܶ��sumRange������ÿ�����������ǲ����еġ�
//���ʵ�ö�̬�滮������һ������dp�������е�i��λ���б������nums��ǰi����(����λ��i)�ĺ͡�
//��������Ҫ֪������[i,j]�ĺͣ��Ϳ���ֱ����dp���±�jλ�ô洢��ֵ(nums��ǰj��Ԫ�صĺ�)-�±�iλ�ô洢��ֵ��nums��ǰi��Ԫ�صĺͣ�
class NumArray {
public:
	NumArray(vector<int>& nums) {
		int num = nums.size();
		dp.resize(num + 1, 0);
		for (int i = 1; i <= num; i++){
			dp[i] = dp[i - 1] + nums[i - 1];
		}
	}

	int sumRange(int i, int j) {
		return dp[j + 1] - dp[i];
	}
private:
	vector<int> dp;
};