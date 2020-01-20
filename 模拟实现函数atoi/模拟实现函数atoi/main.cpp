//题目：https://leetcode-cn.com/problems/string-to-integer-atoi/submissions/

#include<iostream>
//按照要求一步一步来
long long myAtoi(std::string str) {
	size_t i = 0;
	long long sum = 0;//保存转换后的数
	int sig = 1;//标记符号
	while (i<str.size() && str[i] == ' ')//找到第一个非空字符
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
	while (i<str.size() && str[i] >= '0'&&str[i] <= '9')//将字符转成数字
	{
		sum = sum * 10 + str[i] - '0';
		i++;
		if (sum >= 2147483648)//如果大于，说明溢出了
		{
			if (sig == 1)
				return INT_MAX;
			else
				return INT_MIN;
		}
	}
	return sum*sig;
}