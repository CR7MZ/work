//��Ŀ��https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e?f=discussion
#include<iostream>
#include<string>
//˼·��
//���жϵ�һ���ַ��ǲ��Ƿ��š�
//1.Ϊ+��i���Ϊ1������ת���ӵڶ�����ʼ��2.Ϊ-��i���Ϊ1�����ҽ�Check��Ϊture ����ת�������ֺ�Ҫ�ӷ��š�
//���������ַ�����û�������ַ�����ת��Ϊ���֡���sum���棬�˴�sumΪdouble���ͣ���Ϊ���ǵ�int�����ֵ����Сֵ����

double StrToInt(std::string str) {
	size_t i = 0;
	bool Check = false;
	if (str[0]<'0' || str[0]>'9')
	{
		if (!(str[0] == '+' || str[0] == '-'))
			return 0;
		else if (str[0] == '+')
			i = 1;
		else
		{
			Check = true;
			i = 1;
		}
	}
	double sum = 0;
	for (; i<str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			sum = sum * 10 + (str[i] - '0');
		}
		else
			return 0;
	}
	if (Check)
		sum = -sum;
	if (sum>INT_MAX || sum<INT_MIN)
		return 0;
	return sum;
}