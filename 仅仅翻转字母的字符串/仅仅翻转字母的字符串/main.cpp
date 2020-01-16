//��Ŀ��https://leetcode-cn.com/problems/reverse-only-letters/submissions/
#include<iostream>
#include<string>
//˼·�����������±꣬һ����ͷ��һ����β�������ַ��������ͷ��ʼ���±��Ӧ���ַ�������ĸ�ַ�����������һ���±�һ����
//�±���ȣ��������ɡ�
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