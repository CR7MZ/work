//题目：https://leetcode-cn.com/problems/reverse-only-letters/submissions/
#include<iostream>
#include<string>
//思路：定义两个下标，一个从头、一个从尾部互换字符，如果从头开始的下标对应的字符不是字母字符，跳过。另一个下标一样。
//下标相等，跳出即可。
std::string reverseOnlyLetters(std::string S) {
	int i = 0;
	int j = S.size() - 1;
	while (i < j)
	{
		if (!((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122)))
		{
			i++;
			continue;
		}
		if (!((S[j] >= 65 && S[j] <= 90) || (S[j] >= 97 && S[j] <= 122)))
		{
			j--;
			continue;
		}
		char tmp = S[i];
		S[i] = S[j];
		S[j] = tmp;
		i++;
		j--;
	}
	return S;
}