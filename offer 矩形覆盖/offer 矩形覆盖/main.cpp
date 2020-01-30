//题目：https://www.nowcoder.com/questionTerminal/72a5a919508a4251859fb2cfb987a0e6?f=discussion
#include<iostream>
using namespace std;
//递归：
//思路：通过找规律发现：
//n为1时,有一种方法。
//n为2时，有两种方法。
//n为3时，有三种方法。
//n为4时，有五种方法。
//所以我们可以看出这是一个斐波那契数列，n为n时，有f(n-1)+f(n-2)中方法。
class solution
{
public:
//另一种思路：
//同样是斐波那契数列。
//因为有n块矩形，所以就有f(n)种方法。覆盖完全分为两种可能。
//假设第一次是竖着放的，说明还剩n-1块矩形，就有f(n-1)种方法。
//假设第一次是横着放的，则其下面的矩形只能横向放，就有f(n-2)种方法
	int rectCover(int number)//number为n
	{
		if (number <= 0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		//递归，时间慢。
		return rectCover(number - 1) + rectCover(number - 2);

		//也可用迭代，时间能快些。
		int first = 1, sec = 2, thir = 0;
		for (int i = 3; i < number; i++)
		{
			thir = first + sec;
			first = sec;
			sec = thir;
		}
		return thir;
	}
};