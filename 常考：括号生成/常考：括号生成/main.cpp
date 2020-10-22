#include <iostream>
#include <string>
#include <vector>
using namespace std;

//题目：https://leetcode-cn.com/problems/generate-parentheses/
//解析：使用DFS解决

void Func(vector<string>& v, string str, int l, int r, int n){
	if (l > n || r > n || r > l) return;
	if (l == n && r == n) {
		v.push_back(str);
		return;
	}

	Func(v, str + '(', l + 1, r, n);
	Func(v, str + ')', l, r + 1, n);
	return;
}

vector<string> generateParenthesis(int n) {
	vector<string> v;
	Func(v, "", 0, 0, n);
	return v;
}

