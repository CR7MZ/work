//��Ŀ��https://www.nowcoder.com/questionTerminal/8fecd3f8ba334add803bf2a06af1b993?f=discussion
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//����˼·��https://blog.csdn.net/CR7lmz/article/details/104225348
class solution
{
	static bool compare(const string& str1, const string& str2)//����sort�����ıȽ���
	{
		string s1 = str1 + str2;
		string s2 = str2 + str1;
		return s1 < s2;
	}
	string PrintMinNumber(vector<int> numbers)
	{
		string res;
		if (numbers.size() < 0)
			return res;
		vector<string> s;
		for (size_t i = 0; i < numbers.size(); i++)//������ȫ��תΪ�ַ����������ַ��������С�
		{
			s.push_back(to_string(numbers[i]));
		}

		sort(s.begin(), s.end(), compare);//���ַ��������������

		for (size_t i = 0; i < s.size(); i++)//�ַ�����������󣬽�ϳ�һ���ַ�����Ϊ��С������
		{
			res.append(s[i]);
		}
		return res;
	}
};