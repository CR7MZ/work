//��Ŀ��https://www.nowcoder.com/questionTerminal/3194a4f4cf814f63919d0790578d51f3?f=discussion
#include<iostream>
#include<string>
using namespace std;
//˼·��
//1.�Ƚ��ַ������巭ת
//2.����ÿ��С�ĵ��ʽ��з�ת��
string ReverseSentence(string str) {
	reverse(str.begin(), str.end());
	auto it1 = str.begin();
	auto it2 = str.begin();
	while (it2 != str.end())
	{
		if (*it2 == ' ')//��������ո�˵��it1��it2֮���Ѿ���һ�������ˡ���ת
		{
			reverse(it1, it2);
			it1 = it2 + 1;
		}
		if (it2 + 1 == str.end()) //��ת���һ������
			reverse(it1, it2 + 1);
		it2++;
	}
	return str;
}