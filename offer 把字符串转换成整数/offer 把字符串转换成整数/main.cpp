//题目：https://www.nowcoder.com/questionTerminal/1277c681251b4372bdef344468e4f26e?f=discussion
#include<iostream>
#include<string>
//思路：
//先判断第一个字符是不是符号。
//1.为+，i标记为1。下面转换从第二个开始。2.为-，i标记为1，并且将Check置为ture 代表转换成数字后，要加符号。
//如果后面的字符串中没有其他字符，则转换为数字。用sum保存，此处sum为double类型，因为考虑到int的最大值，最小值问题

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