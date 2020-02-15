//题目：https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1?f=discussion
#include<iostream>
//递归进行相加，判断结束的条件为re&&，也就是说当re为0了，则不进行&&后面的运算了
//利用了运算符短路的性质。
int Sum_Solution(int n) {
	int re = n;
	re && (re += Sum_Solution(n - 1));
	return re;
}