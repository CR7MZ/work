#include <iostream>
#include <vector>
using namespace std;

//��Ŀ��ɭ������N������ָ��ĳһ������ô����������(���˴�ָ������)����������1��������ָ�򼸴βſ���ʹɭ���е����߶�ƽ�⡣

//��������+1��������Ϊ��ָ�����-1����˼���������ľ�߶���ɭ������С�߶ȵĲ�ֵ֮�͡����ɡ�

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int min = INT_MAX;
		for (int i = 0; i<nums.size(); i++){
			if (min > nums[i]){
				min = nums[i];
			}
		}

		int res = 0;
		for (int i = 0; i<nums.size(); i++){
			res += nums[i] - min;
		}
		return res;
	}
};