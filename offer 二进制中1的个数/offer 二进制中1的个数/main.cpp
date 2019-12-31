//题目：https://www.nowcoder.com/questionTerminal/8ee967e43c2c4ec193b040ea7fbb10b8?f=discussion
#include<iostream>
using namespace std;
//思路：如果一个数不为0，那么说明这个整数至少有一位为1。如果此时，我们将这个整数-1，那么整数中最右边的1，变为0，之前在1后面的0，全部变为1
//其余为不会受到影响。
//举个例子：二进制数1100，-1位1011，这时可以发现减去1整数最右边的1变为0,1后面的0全部变为1。
//将原来的整数和减后整数按位与，得到1000，就将最右边的1变为0。
//那么我们要得到二进制树中有几个1，就可以通过把一个整数减去1，再将其与原来的整数按位与，把整数有1的位变为0，知道整数为0。
int NumberOf1(int n) {
	int count = 0;
	while (n != 0){
		count++;
		n = n & (n - 1);
	}
	return count;
}