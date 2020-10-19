#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//题目：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

//使用DFS+unordered_map，进行递归
void Func(unordered_map<char, string>& m, vector<string>& v, string str, string& digits, int k){
	if (str.size() == digits.size()) {
		v.push_back(str);
		return;
	}

	string tmp = m[digits[k]];
	for (auto e : tmp){
		str += e;
		Func(m, v, str, digits, k + 1);
		str.pop_back();
	}
	return;
}

vector<string> letterCombinations(string digits) {
	unordered_map<char, string> m{
			{ '0', " " }, { '1', "*" }, { '2', "abc" },
			{ '3', "def" }, { '4', "ghi" }, { '5', "jkl" },
			{ '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" },
			{ '9', "wxyz" }
	};
	vector<string> v;
	if (digits.empty()) return v;
	Func(m, v, "", digits, 0);
	return v;
}

