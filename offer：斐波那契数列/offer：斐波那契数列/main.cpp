#include <iostream>
#include <vector>
using namespace std;

//题目：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/

//使用递归时间复杂度太高，超时
int fib(int n) {
	if (n == 0 || n == 1)
		return n % 1000000007;
	
	int a = 0, b = 1;
	for (int i = 1; i<n; i++)
	{
		b = a + b;
		a = b - a;
		b %= 1000000007;
	}
	return b;
}
