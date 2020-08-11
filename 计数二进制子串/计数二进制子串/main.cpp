#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//题目：https://leetcode-cn.com/problems/count-binary-substrings/

//思路：
//统计连续的1和0分别有多少个，在统计出来一组数中每相邻两个数之间找出最小值，加起来，就为最终答案。
//例如：111100011000 ，得到4323。在4323中任意两个相邻数字中，取出最小值加起来，为3+2+2 = 7。
int countBinarySubstrings(string s) {
	vector<int> v;
	int sum = 1;
	//统计出连续的1和0个数
	auto it = s.begin() + 1;
	while (it != s.end()){
		if (*it == *(it - 1)){
			++sum;
		}
		else {
			v.push_back(sum);
			sum = 1;

		}
		it++;
	}
	v.push_back(sum);

	//取出任意两个相邻数字的最小值相加。
	sum = 0;
	for (int i = 0; i < v.size() - 1; i++){
		sum += min(v[i], v[i + 1]);
	}
	return sum;
}


//大佬思路：
	//用last记录前面数字出现的次数，cur记录后面数字出现的次数，当last>cur时，res++。
int countBinarySubstrings(string s) {
	int last, cur, res; last = res = 0; cur = 1;
	for (int i = 1; i<s.size(); i++){
		if (s[i] == s[i - 1]) cur++;
		else{ last = cur; cur = 1; }
		if (last >= cur) res++;
	}
	return res;
}
