//��Ŀ��https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6?f=discussion
#include<iostream>
//��Ŀ������https://blog.csdn.net/CR7lmz/article/details/104224227
int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i *= 10)
	{
		int a = n / i;//��λ
		int b = n % i;//��λ
		count += (a + 8) / 10 * i + (a % 10 == 1)*(b + 1);
	}
	return count;
}