//题目：https://www.nowcoder.com/questionTerminal/12d959b108cb42b1ab72cef4d36af5ec?f=discussion
#include<iostream>
#include<string>
#include<queue>
using namespace std;
//思路：
//用队列，将字符串放入队列中，出队n次，将出队的数据按顺序放回队列尾部。将队列中的字符合而成字符串。
string LeftRotateString(string str, int n) {
	queue<char> q;
	for (auto e : str)
	{
		q.push(e);
	}
	while (n)
	{
		int tmp = q.front();
		q.pop();
		q.push(tmp);
		n--;
	}
	for (int i = 0; i<str.size(); i++)
	{
		str[i] = q.front();
		q.pop();
	}
	return str;
}

//大神思路：
//将字符串旋转两遍，可以找个例子模拟一下。
string LeftRotateString(string str, int n) {
	reverse(str.begin(), str.end());
	reverse(str.begin(), str.begin() + str.size() - n);
	reverse(str.begin() + str.size() - n, str.end());
	return str;
}