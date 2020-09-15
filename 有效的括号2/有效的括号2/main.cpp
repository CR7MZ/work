#include <iostream>
#include <stack>
using namespace std;
//题目：https://leetcode-cn.com/problems/valid-parentheses/

//根据askii值来判断是否匹配。因为：
//'(' + 1 == ')'  
//'{' + 2 == '}'  
//'[' + 2 == ']'

bool isValid(string s) {
	stack<char> st;
        for(auto e : s){
            if(!st.empty()&&(st.top()+1 == e || st.top()+2 == e)){
                st.pop();
            } else {
                st.push(e);
            }
        }
        return st.empty();
}