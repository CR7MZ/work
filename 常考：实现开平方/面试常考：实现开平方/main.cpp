#include <iostream>
using namespace std;

//https://blog.csdn.net/xusiwei1236/article/details/25657611

double My_Sqrt(double x)
{
	double a = 0.0, b = x + 0.25, mid;
	while (1){
		mid = (a + b) / 2;
		if (mid - a < DBL_EPSILON || b - mid < DBL_EPSILON) break;
		if ((mid * mid - x) * (a * a - x) < 0){
			b = mid;
		}else {
			a = mid;
		}
	}
	return mid;
}

int main()
{
	double x = 25;
	cout << My_Sqrt(x) << endl;
	return 0;
}