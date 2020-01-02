//题目：https://leetcode-cn.com/problems/squares-of-a-sorted-array/submissions/
#include<iostream>
#include<vector>
//因为是非递减序列， 所以存在负数并且在数组中左边，先定义两个下标，从头尾开始比较，如果从头开始的负数变为正数后比从尾部遍历的数大
//则平方后放在新的数组v中，v的大小要和原数组一样大。一直到i>j或者k<0为止。
std::vector<int> sortedSquares(std::vector<int>& A)
{
	std::vector<int> v(A.size());
	int i = 0;
	int j = A.size() - 1;
	int k = v.size() - 1;//记录新数组最后的下标，标记最大数放的为止。
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