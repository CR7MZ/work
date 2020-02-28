//题目：https://www.nowcoder.com/questionTerminal/623a5ac0ea5b4e5f95552655361ae0a8?f=discussion
#include<iostream>
#include<vector>
//定义一个存放bool类型的数组v，初始化为false
//把numbers中的数当做v的下标，numbers中的数出现了，就将相应位置置为true。
//若在V中找到值为true的位置，将位置返回，此为第一个重复出现的数字。
bool duplicate(int numbers[], int length, int* duplication) {
	std::vector<bool> v(length, false);
	for (int i = 0; i<length; i++)
	{
		if (v[numbers[i]] == true)
		{
			*duplication = numbers[i];
			return true;
		}
		v[numbers[i]] = true;
	}
	return false;
}