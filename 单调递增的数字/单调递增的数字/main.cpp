#include <iostream>
#include <string>
using namespace std;

//题目：https://leetcode-cn.com/problems/monotone-increasing-digits/
//解析：从后往前扫描数字，如果发现当前数字比起左边数字小，将当前数字左边数字-1，当前数字右边全为9

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