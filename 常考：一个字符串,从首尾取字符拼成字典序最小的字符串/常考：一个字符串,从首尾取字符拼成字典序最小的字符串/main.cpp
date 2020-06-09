#include <iostream>
#include <string>

using namespace std;

//�ַ�����ÿ�δ��ײ���β��ȡһ���ַ���ƴ�ӳ�Ŀ���ַ�����ʹ���ֵ�����С��
//ʹ��˫ָ��

string ProcString(const string& s)
{
	if (s.empty() || s.size() <= 1)
		return s;
	string res; 

	//��������ָ�룬�ֱ�ָ��ͷ��β
	int left = 0;
	int right = s.size() - 1;

	//��ָ��ָ����ַ����бȽϣ�С�ķ����µ��ַ����
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

		//�����ַ���ȣ���������ȥ�����Ҳ���ȵ��ַ�
		else
		{
			int i = left;
			int j = right;
			while (i < j && s[j] == s[i])
			{
				++i; 
				--j;
			}
			if (i == j)         //˵����������Ԫ��Ⱥ�����
			{
				res += s[left];
				++left;
				continue;
			}
			if (s[i] < s[j])    //�ҵ�����ȵ��ַ��������С����leftָ����ַ��������ַ����С�
			{
				res += s[left];
				++left;
			}
			else                //���򣬽�rightָ����ַ��������ַ����С�	
			{
				res += s[right];
				--right;
			}
		}
	}
	return res;
}