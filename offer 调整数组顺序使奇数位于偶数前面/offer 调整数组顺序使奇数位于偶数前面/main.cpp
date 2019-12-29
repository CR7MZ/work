//题目：https://www.nowcoder.com/questionTerminal/beb5aa231adc45b2a5dcc5b62c93f593?f=discussion
#include<iostream>
#include<vector>
//思路：定义一个数组来放偶数。遍历数组，遇到偶数将其放入新数组中，并且将其从原数组中删除。这样即将奇数、偶数分开。并且相对位置不变。
//最后将所有偶数插入原数组中。
void reOrderArray(std::vector<int> &array) {
	int size = array.size();
	std::vector<int> tmp;
	auto it = array.begin();
	while (it != array.end())
	{
		if ((*it) % 2 == 0)
		{
			tmp.push_back(*it);
			it = array.erase(it);
		}
		else
			it++;
	}
	for (auto e : tmp)
	{
		array.push_back(e);
	}
}