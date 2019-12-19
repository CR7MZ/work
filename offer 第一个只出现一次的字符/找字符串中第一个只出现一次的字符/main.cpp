//题目：https://www.nowcoder.com/questionTerminal/1c82e8cf713b4bbeb2a5b31cf5b0417c?f=discussion
#include<iostream>
#include<vector>
using namespace std;
//思路：
//因为字符串ASKII范围为0-256，所以建立一个范围为256的数组，全部初始化为0。
//遍历字符串通过ASKii码找到字符对应的下标，统计次数。
	int firstUniqchar(string s)
	{
		//字符串范围：0~256
		//1.统计每一个字符出现的次数
		vector<int> count(256, 0);
		for (auto e : s)
			count[e]++;
		//2.找到第一个出现一次的字符的下标，并返回。
		for (int i = 0; i < s.size(); ++i)
		{
			if (1 == count[s[i]])
			{
				return i;
			}
		}
		return -1;
	}