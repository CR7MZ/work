//��Ŀ��https://leetcode-cn.com/problems/squares-of-a-sorted-array/submissions/
#include<iostream>
#include<vector>
//��Ϊ�Ƿǵݼ����У� ���Դ��ڸ�����������������ߣ��ȶ��������±꣬��ͷβ��ʼ�Ƚϣ������ͷ��ʼ�ĸ�����Ϊ������ȴ�β������������
//��ƽ��������µ�����v�У�v�Ĵ�СҪ��ԭ����һ����һֱ��i>j����k<0Ϊֹ��
std::vector<int> sortedSquares(std::vector<int>& A)
{
	std::vector<int> v(A.size());
	int i = 0;
	int j = A.size() - 1;
	int k = v.size() - 1;//��¼�����������±꣬���������ŵ�Ϊֹ��
	while (i <= j&&k >= 0)
	{
		if (-A[i] < A[j])
		{
			v[k] = A[j] * A[j];
			j--;
			k--;
			continue;
		}
		else
		{
			v[k] = A[i] * A[i];
			i++;
			k--;
		}
	}
	return v;
}
int main()
{
	std::vector<int>a = { -4, -1, 0, 3, 10 };
	std::vector<int> s =sortedSquares(a);
	return 0;
}