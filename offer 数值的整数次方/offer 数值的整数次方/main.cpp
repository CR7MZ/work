//ÌâÄ¿£ºhttps://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00?f=discussion
#include<iostream>
double Power(double base, int exponent)
{
	if (base == 0 && exponent == 0)
		return 0;
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	double res = base;
	if (exponent<0)
	{
		exponent = -exponent;
		for (int i = 1; i<exponent; i++)
			res *= base;
		res = 1 / res;
		return res;
	}
	else
	{
		for (int i = 1; i<exponent; i++)
			res *= base;
		return res;
	}
	return 0;
}