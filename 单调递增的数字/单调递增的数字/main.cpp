#include <iostream>
#include <string>
using namespace std;

//��Ŀ��https://leetcode-cn.com/problems/monotone-increasing-digits/
//�������Ӻ���ǰɨ�����֣�������ֵ�ǰ���ֱ����������С������ǰ�����������-1����ǰ�����ұ�ȫΪ9

class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		string s = to_string(N);
		int index = s.size();
		for (int i = s.size() - 1; i>0; i--){
			if (s[i - 1] - '0' > s[i] - '0'){
				s[i - 1]--;
				index = i;
			}
		}

		for (int i = index; i < s.size(); i++){
			s[i] = '9';
		}
		return atoi(s.c_str());
	}
};