//题目：https://www.nowcoder.com/questionTerminal/3194a4f4cf814f63919d0790578d51f3?f=discussion
#include<iostream>
#include<string>
using namespace std;
//思路：
//1.先将字符串整体翻转
//2.最后对每个小的单词进行翻转。
string ReverseSentence(string str) {
	reverse(str.begin(), str.end());
	auto it1 = str.begin();
	auto it2 = str.begin();
	while (it2 != str.end())
	{
		if (*it2 == ' ')//如果遇到空格说明it1和it2之间已经有一个单词了。翻转
		{
			reverse(it1, it2);
			it1 = it2 + 1;
		}
		if (it2 + 1 == str.end()) //翻转最后一个单词
			reverse(it1, it2 + 1);
		it2++;
	}
	return str;
}