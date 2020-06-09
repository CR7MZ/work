#include <iostream>

using namespace std;

//题目：假设有两个函数 rand3()可以产生随机的0、1、2，rand5()可以产生随机的0、1、2、3、4，
//现在请你利用它编写一个函数rand7()，产生0~6的随机数。

//方法1
int rand7()
{
	int a[3][3] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int row, col;
	do
	{
		row = rand3();
		col = rand3();
	} while (a[row][col] > 6);

	return a[row][col];
}

//方法2 
int rand7(int)
{
	int res = 0;
	do
	{
		switch (rand3())
		{
		case 0:
			res = rand3();
		case 1:
			res = rand3()+3;
		case 2:
			res = rand3() + 6;
		}
	} while (res > 6);

	return res;
}
