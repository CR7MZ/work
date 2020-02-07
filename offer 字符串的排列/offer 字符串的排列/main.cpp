//题目：https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7?f=discussion
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> Permutation(string str)
{
	vector<string> res;
	if (str.empty())
		return res;
	Permutation(str, res, 0);
	sort(res.begin(), res.end());//因为输出的排列可能不是字典序排列，所以再返回答案前需要自己进行排序。
	return res;
}
void Permutation(string str, vector<string>& res, int begin)//进行字符串的排序操作
{
	if (begin == str.size() - 1)//递归终止条件，说明只剩最后一个元素。
	{
		if (find(res.begin(), res.end(), str) == res.end())//如果此时res不存在str，则添加。避免重复添加的情况。
			res.push_back(str);
	}
	else
	{
		//第一次循环i和begin是相等的，相当于第一个位置自身交换，
		//之后i和begin不相等，则会交换两个不同位置上的字符，直到begin==str.size()-1;才能输入到数组中。
		for (size_t i = begin; i < str.size(); i++)
		{
			swap(str[i], str[begin]);
			Permutation(str, res, begin + 1);
			swap(str[i], str[begin]);//复位。（说明此时首字母为a的所有情况：abc,acb已经给入数组）
			//再用最开始的字符串顺序（abc），达到第一位依次和其他为互换的目的。所以要复位。
		}
	}
}