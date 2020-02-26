//题目：https://www.nowcoder.com/questionTerminal/6aa9e04fc3794f68acf8778237ba065b?f=discussion
#include<iostream>
#include<vector>
#include<algorithm>//包含min函数

//思路解析：https://blog.csdn.net/CR7lmz/article/details/104236166
int GetUglyNumber_Solution(int index) {
	if (index<7)
		return index;
	std::vector<int> res(index);
	res[0] = 1;
	int p2 = 0, p3 = 0, p5 = 0;
	for (int i = 1; i<index; i++)
	{
		res[i] = std::min(res[p2] * 2, std::min(res[p3] * 3, res[p5] * 5));
		if (res[i] == res[p2] * 2)p2++;
		if (res[i] == res[p3] * 3)p3++;
		if (res[i] == res[p5] * 5)p5++;
	}
	return res[index - 1];
}