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

//自己实现reverse函数
void Reverse(string& s, int i, int j){
	while (i < j){
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++; j--;
	}
}
string ReverseSentence(string str) {
	if (str.empty()){
		return str;
	}
	bool l = false;
	Reverse(str, 0, str.size() - 1);

	int j = 0, i = 0;
	for (; i < str.size(); i++){
		if (str[i] == ' ' && i == 0 && j  ==0){
			j = i + 1;
			continue;
		}
		else if (str[i] == ' ' ){
			Reverse(str, j, i - 1);
			j = i + 1;
			
		}
		else if (j == str.size()){
			l = true;
			break;
		}
	}
	if (l == false){
		Reverse(str, j, i - 1);
	}

	return str;
}