//题目：https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215?f=discussion
#include<iostream>
//思路：
//用位运算
//异或相当于做加法
//按位与并左移一位相当于查看你是否有进位
//当num==0说明没有进位了，则num1则为结果。
int Add(int num1, int num2)
{
	while (num2 != 0)
	{
		int sum = num1^num2;
		int car = (num1&num2) << 1;
		num1 = sum;
		num2 = car;
	}
	return num1;
}