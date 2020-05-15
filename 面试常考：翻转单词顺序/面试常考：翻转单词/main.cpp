#include <iostream>
#include <string>
using namespace std;

//�Ƚ�������ת���ٷ�ת��������
void ReverseWord(string &str, int s, int e)
{
	while (s < e)
		swap(str[s++], str[e--]);
}

string ReverseSentence(string str) {
	ReverseWord(str, 0, str.size() - 1); //�����巭ת
	int s = 0, e = 0;
	int i = 0;
	while (i < str.size())
	{
		while (i < str.size() && str[i] == ' ') //�ո�����
			i++;
		e = s = i; //��¼���ʵĵ�һ���ַ���λ��
		while (i < str.size() && str[i] != ' ') //���ǿո� �ҵ������һ���ַ���λ��
		{
			i++;
			e++;
		}
		ReverseWord(str, s, e - 1); //�ֲ���ת
	}
	return str;
}