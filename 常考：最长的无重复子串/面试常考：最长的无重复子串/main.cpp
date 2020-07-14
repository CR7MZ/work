#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//题目及解析：https://www.cnblogs.com/eilearn/p/9541232.html

int lengthOfLongestSubstring(const string& s)
{
	if (s.empty())
		return 0;
	unordered_map<char, int> um;
	int left = 0, res = 0;

	for (int i = 0; i < s.size(); i++)
	{
		//更新窗口的左边界
		//如果此时扫描到的单词之前出现过
		//1.之前出现的字符在滑动窗口内，则需要更新left。
		//2.之前出现的字符不在滑动窗口内，则当前字符可以加进来
		left = max(left, um[s[i]]);

		//更新新加入字符的位置。
		um[s[i]] = i + 1;
		res = max(res, i - left + 1);
	}
	return res;
}