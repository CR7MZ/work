//题目：https://www.nowcoder.com/questionTerminal/6f8c901d091949a5837e24bb82a731f2?f=discussion
#include<iostream>
//思路：
//分情况考虑
bool isNumeric(char* string)
{
	//标记 e/E、.、+/-是否出现
	bool Point = false, Signal = false, HasE = false;
	for (size_t i = 0; i<strlen(string); i++)
	{
		if (string[i] == 'E' || string[i] == 'e')
		{
			if (i == strlen(string) - 1) return false;//出现E后面必须需有元素
			if (HasE) return false;//E只能出现一次
			HasE = true;
		}
		else if (string[i] == '-' || string[i] == '+')
		{
			//第二次出现符号，必须在E后面
			if (Signal&&string[i - 1] != 'e'&&string[i - 1] != 'E') return false;
			//第一次出现符号，且不在头，也必须在E后面
			if (!Signal&&i>0 && string[i - 1] != 'e'&&string[i - 1] != 'E') return false;
			Signal = true;
		}
		else if (string[i] == '.')
		{
			//只能有一个.，E后面不能有.
			if (HasE || Point) return false;
			Point = true;
		}
		else if (string[i]<'0' || string[i]>'9')
		{
			//只能是数字字符
			return false;
		}
	}
	return true;
}