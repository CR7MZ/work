//��Ŀ��https://www.nowcoder.com/questionTerminal/12d959b108cb42b1ab72cef4d36af5ec?f=discussion
#include<iostream>
#include<string>
#include<queue>
using namespace std;
//˼·��
//�ö��У����ַ�����������У�����n�Σ������ӵ����ݰ�˳��Żض���β�����������е��ַ��϶����ַ�����
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

//����˼·��
//���ַ�����ת���飬�����Ҹ�����ģ��һ�¡�
string LeftRotateString(string str, int n) {
	reverse(str.begin(), str.end());
	reverse(str.begin(), str.begin() + str.size() - n);
	reverse(str.begin() + str.size() - n, str.end());
	return str;
}