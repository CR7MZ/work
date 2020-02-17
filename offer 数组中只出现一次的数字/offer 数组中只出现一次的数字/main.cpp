//题目：https://www.nowcoder.com/questionTerminal/e02fdb54d7524710a7d664d082bb7811?f=discussion
#include<iostream>
#include<vector>
//思路：用异或的方法。
//1.因为异或的属性，将数组全部异或得到两个只出现一次（称作A、B）的数异或的结果res。
//2.因为异或是：相同为0，相异为1。所以res所有为1的比特位，就是AB两数字相异的比特位，因此我们要找res第一个为1的比特位的位置index。
//3.用index把原数组分为两组，分组标准是第index为是否为1.
//4.如此，两个不同的数AB就分开了，最后将两数组分别异或，得到两个只出现一次的数。

int Findfir1(int tmp)//找到二进制res中第一1的位置
{
	int i = 0;
	for (; i<32; i++)
	{
		if ((tmp & 1) == 1)
			return i;
		tmp >>= 1;
	}
	return -1;
}
bool Func(int x, int index)//根据判断index位是否为1
{
	return (((x >> index) & 1) == 1);
}
void FindNumsAppearOnce(std::vector<int> data, int* num1, int *num2) {
	if (data.size() == 2)
	{
		*num1 = data[0];
		*num2 = data[1];
	}
	else
	{
		*num1 = 0;
		*num2 = 0;
		int res = 0;
		for (size_t i = 0; i<data.size(); i++)
		{
			res ^= data[i];
		}
		int index = Findfir1(res);
		for (size_t i = 0; i<data.size(); i++)
		{
			if (Func(data[i], index))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
	}
}
