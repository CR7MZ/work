#include <iostream>
#include <stack>
using namespace std;
//��Ŀ��https://leetcode-cn.com/problems/valid-parentheses/

//����askiiֵ���ж��Ƿ�ƥ�䡣��Ϊ��
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