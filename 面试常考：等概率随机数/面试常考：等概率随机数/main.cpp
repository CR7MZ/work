#include <iostream>

using namespace std;

//��Ŀ���������������� rand3()���Բ��������0��1��2��rand5()���Բ��������0��1��2��3��4��
//����������������дһ������rand7()������0~6���������

//����1
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

//����2 
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
