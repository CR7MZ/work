//��Ŀ��https://www.nowcoder.com/questionTerminal/1c82e8cf713b4bbeb2a5b31cf5b0417c?f=discussion
#include<iostream>
#include<vector>
using namespace std;
//˼·��
//��Ϊ�ַ���ASKII��ΧΪ0-256�����Խ���һ����ΧΪ256�����飬ȫ����ʼ��Ϊ0��
//�����ַ���ͨ��ASKii���ҵ��ַ���Ӧ���±꣬ͳ�ƴ�����
	int firstUniqchar(string s)
	{
		//�ַ�����Χ��0~256
		//1.ͳ��ÿһ���ַ����ֵĴ���
		vector<int> count(256, 0);
		for (auto e : s)
			count[e]++;
		//2.�ҵ���һ������һ�ε��ַ����±꣬�����ء�
		for (int i = 0; i < s.size(); ++i)
		{
			if (1 == count[s[i]])
			{
				return i;
			}
		}
		return -1;
	}