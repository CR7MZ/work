//题目：https://www.nowcoder.com/questionTerminal/8fecd3f8ba334add803bf2a06af1b993?f=discussion
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//解题思路：https://blog.csdn.net/CR7lmz/article/details/104225348
class solution
{
	static bool compare(const string& str1, const string& str2)//定义sort函数的比较器
	{
		string s1 = str1 + str2;
		string s2 = str2 + str1;
		return s1 < s2;
	}
	string PrintMinNumber(vector<int> numbers)
	{
		string res;
		if (numbers.size() < 0)
			return res;
		vector<string> s;
		for (size_t i = 0; i < numbers.size(); i++)//将数字全部转为字符串，放入字符串数组中。
		{
			s.push_back(to_string(numbers[i]));
		}

		sort(s.begin(), s.end(), compare);//对字符串数组进行排序。

		for (size_t i = 0; i < s.size(); i++)//字符串数组排序后，结合成一个字符串，为最小的数。
		{
			res.append(s[i]);
		}
		return res;
	}
};