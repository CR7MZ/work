#include <iostream>
using namespace std;

double My_pow_1(double x, double y)//·ÇµÝ¹é
{
	double res = 1;
	for (int i = 0; i < y; i++)
	{
		res *= x;
	}
	return res;
}

double My_pow_2(double x, double y)//µÝ¹é
{
	if (y == 0)
		return 1;
	return x * My_pow_2(x, y - 1);
}


int main()
{
	cout << My_pow_1(2.1, 2.0) << endl;
	system("pause");
	return 0;
}