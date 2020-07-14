#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//��Ŀ��������https://www.cnblogs.com/eilearn/p/9541232.html

int lengthOfLongestSubstring(const string& s)
{
	if (s.empty())
		return 0;
	unordered_map<char, int> um;
	int left = 0, res = 0;

	for (int i = 0; i < s.size(); i++)
	{
		//���´��ڵ���߽�
		//�����ʱɨ�赽�ĵ���֮ǰ���ֹ�
		//1.֮ǰ���ֵ��ַ��ڻ��������ڣ�����Ҫ����left��
		//2.֮ǰ���ֵ��ַ����ڻ��������ڣ���ǰ�ַ����Լӽ���
		left = max(left, um[s[i]]);

		//�����¼����ַ���λ�á�
		um[s[i]] = i + 1;
		res = max(res, i - left + 1);
	}
	return res;
}