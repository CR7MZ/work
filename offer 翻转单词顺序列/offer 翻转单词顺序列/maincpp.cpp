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

//�Լ�ʵ��reverse����
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