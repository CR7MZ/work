//��Ŀ��https://leetcode-cn.com/problems/string-to-integer-atoi/submissions/

#include<iostream>
//����Ҫ��һ��һ����
long long myAtoi(std::string str) {
	size_t i = 0;
	long long sum = 0;//����ת�������
	int sig = 1;//��Ƿ���
	while (i<str.size() && str[i] == ' ')//�ҵ���һ���ǿ��ַ�
		++i;
	if (str[i] == '-')
	{
		sig = -1;
		++i;
	}
	else if (str[i] == '+')
	{
		sig = 1;
		++i;
	}
	while (i<str.size() && str[i] >= '0'&&str[i] <= '9')//���ַ�ת������
	{
		sum = sum * 10 + str[i] - '0';
		i++;
		if (sum >= 2147483648)//������ڣ�˵�������
		{
			if (sig == 1)
				return INT_MAX;
			else
				return INT_MIN;
		}
	}
	return sum*sig;
}