//题目：https://www.nowcoder.com/questionTerminal/00de97733b8e4f97a3fb5c680ee10720?f=discussion
#include <iostream>
#include <queue>

//思路：
//定义一个数组来对字符进行计数，再定义一个队列，将第一次出现的字符放入，最后通过获取队列头元素来通过数组判断是不是只出现一次的字符
//若是，则此字符就是第一个不重复出现的字符。
int v[256];
std::queue<char> tmp;

void Insert(char ch)
{
	v[ch]++;
	if (v[ch] == 1)
		tmp.push(ch);
}
char FirstAppearingOnce()
{
	while (!tmp.empty() && v[tmp.front()]>1)
		tmp.pop();
	if (tmp.empty()) return '#';
	return tmp.front();
}
void Func()
{
	memset(v, 0, sizeof(v));//给数组赋值为0
}

