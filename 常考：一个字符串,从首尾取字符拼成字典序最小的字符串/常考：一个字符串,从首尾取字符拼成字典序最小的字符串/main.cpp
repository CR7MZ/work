#include <iostream>
#include <string>

using namespace std;

//字符串，每次从首部或尾部取一个字符，拼接成目标字符串，使得字典序最小。
//使用双指针

string ProcString(const string& s)
{
	if (s.empty() || s.size() <= 1)
		return s;
	string res; 

	//定义两个指针，分别指向头、尾
	int left = 0;
	int right = s.size() - 1;

	//两指针指向的字符进行比较，小的放入新的字符串里。
	while (left <= right)
	{
		if (s[left] < s[right])
		{
			res += s[left];
			++left;
		}
		else if (s[left] > s[right])
		{
			res += s[right];
			--right;
		}

		//若两字符相等，则向中心去找左右不相等的字符
		else
		{
			int i = left;
			int j = right;
			while (i < j && s[j] == s[i])
			{
				++i; 
				--j;
			}
			if (i == j)         //说明中心左右元素群不相等
			{
				res += s[left];
				++left;
				continue;
			}
			if (s[i] < s[j])    //找到不相等的字符后，若左边小，则将left指向的字符插入新字符串中。
			{
				res += s[left];
				++left;
			}
			else                //否则，将right指向的字符插入新字符串中。	
			{
				res += s[right];
				--right;
			}
		}
	}
	return res;
}