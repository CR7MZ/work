//题目：https://www.nowcoder.com/questionTerminal/8c82a5b80378478f9484d87d1c5f12a4?f=discussion
#include<iostream>
//1.迭代
//思路:通过前面找规律发现，如果只有一个台阶f(1),则只有一种跳法。若只有两个台阶f(2)，则有两种跳法。f(3)有三种，f(4)有5中。
//我们可以发现f(n)=f(n-1)+f(n-2)。但是为什么会有这样的规律呢？因为青蛙一次只能跳一个或者两个台阶。所以假设现在5个台阶，
//我们可以从第4个台阶跳一步到第5个台阶，所以有多少种方案跳到第4个台阶，就有多少种方案到第5个台阶。
//也可以从第3个台阶跳两步到底5个台阶。所以有多少种方案跳到第3个台阶，就有多少种方案到第5个台阶。
//所以就有f(5)=f(4)+f(3)
class solution
{
public:
	int jumpFloor(int number) {
		if (number<0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		int fir = 1, sec = 2, thir = 0;
		for (int i = 3; i <= number; i++)
		{
			thir = fir + sec;
			fir = sec;
			sec = thir;
		}
		return thir;
	}

//2.递归
//本题说明有两种跳法。假设第一次跳了1个台阶，那么剩下n-1个台阶，也就有f(n-1)中跳法。
//假设第一次跳了2个台阶，那么剩下n-2个台阶，也就有f(n-1)中跳法。
//可以得出总跳法有f(n)=f(n-1)+f(n-2)
//我们很容易直到f(1)=1,f(2)=2。
//最终可以发现，得出的算是一个斐波那契数列。
	int jumpFloor(int number) {
		if (number<0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		return jumpFloor(number-1) + jumpFloor(number - 2);
	}
};
int main()
{
	solution s;
	std::cout<<s.jumpFloor(4)<<std::endl;
	system("pause");
	return 0;
}