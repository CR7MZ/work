//��Ŀ��https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46?f=discussion
#include<iostream>
#include<vector>

//˼·��
//ͼ����Ŀ��            
//��һ��ͼ���ȴ������¼����°벿�����ǣ������b[i]��һ���֣����ٴ������ϼ����ϰ벿�����ǣ�b[i]����һ���֣�����󽫶�����˼��ɵõ�����b[i]��
std::vector<int> multiply(const std::vector<int>& A) {
	std::vector<int> b(A.size(), 0);
	int n = A.size();
	b[0] = 1;
	for (int i = 1; i<n; i++)
	{
		b[i] = b[i - 1] * A[i - 1];
	}
	int tmp = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		tmp *= A[i + 1];
		b[i] *= tmp;
	}
	return b;
}

//����˼·��
//��������
int Func(int x, const std::vector<int>& A)//ֱ�Ӽ����ÿ��b[i]�Ľṹ�����ء�
{
	int res = 1;
	if (x == 0)
	{
		for (int i = 1; i<A.size(); i++)
		{
			if (i == x)
				continue;
			res *= A[i];
		}
	}
	else if (x == A.size() - 1)
	{
		for (int i = 0; i<A.size() - 1; i++)
		{
			if (i == x)
				continue;
			res *= A[i];
		}
	}
	else
	{
		for (int i = 0; i<A.size(); i++)
		{
			if (i == x)
				continue;
			res *= A[i];
		}
	}
	return res;
}
std::vector<int> multiply(const std::vector<int>& A,int) {
	std::vector<int> b(A.size(), 0);
	for (int i = 0; i<A.size(); i++)
	{
		b[i] = Func(i, A);
	}
	return b;
}