#include <iostream>
#include <stack>
using namespace std;
//ÌâÄ¿£ºhttps://leetcode-cn.com/problems/valid-parentheses/


bool isValid(string s) {
	stack<char> c;
	for (auto e : s){
		if (c.empty()){
			c.push(e);
			continue;
		}
		if (e == ')' && c.top() != '(' || e == '}' && c.top() != '{' || e == ']' && c.top() != '['){
			c.push(e);
		}
		else if (e == ')' && c.top() == '(' || e == '}' && c.top() == '{' || e == ']' && c.top() == '['){
			c.pop();
		}
		else {
			c.push(e);
		}
	}
	if (!c.empty()){
		return false;
	}
	return true;
}