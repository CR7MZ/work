//��Ŀ��https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7?f=discussion
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> Permutation(string str)
{
	vector<string> res;
	if (str.empty())
		return res;
	Permutation(str, res, 0);
	sort(res.begin(), res.end());//��Ϊ��������п��ܲ����ֵ������У������ٷ��ش�ǰ��Ҫ�Լ���������
	return res;
}
void Permutation(string str, vector<string>& res, int begin)//�����ַ������������
{
	if (begin == str.size() - 1)//�ݹ���ֹ������˵��ֻʣ���һ��Ԫ�ء�
	{
		if (find(res.begin(), res.end(), str) == res.end())//�����ʱres������str������ӡ������ظ���ӵ������
			res.push_back(str);
	}
	else
	{
		//��һ��ѭ��i��begin����ȵģ��൱�ڵ�һ��λ����������
		//֮��i��begin����ȣ���ύ��������ͬλ���ϵ��ַ���ֱ��begin==str.size()-1;�������뵽�����С�
		for (size_t i = begin; i < str.size(); i++)
		{
			swap(str[i], str[begin]);
			Permutation(str, res, begin + 1);
			swap(str[i], str[begin]);//��λ����˵����ʱ����ĸΪa�����������abc,acb�Ѿ��������飩
			//�����ʼ���ַ���˳��abc�����ﵽ��һλ���κ�����Ϊ������Ŀ�ġ�����Ҫ��λ��
		}
	}
}