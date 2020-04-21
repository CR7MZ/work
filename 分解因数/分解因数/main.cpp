#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5

int main()
{
	int n;
	while (cin >> n)
	{
		cout << n << " = ";
		vector<int> v;
		int tmp = n;
		for (int i = 2; i <= sqrt(tmp); i++)
		{
			while (n%i == 0)//如果求余数为0，则说明是一个素数，放入数数组中
			{
				if (n != 1)//找到一个素数，就将其除尽。
				{
					v.push_back(i);
					n /= i;
				}
			}
		}
		if (n != 1)//如果最后n不为1说明，为最后一个素数
		{
			v.push_back(n);
		}
		for (int i = 0; i<v.size(); i++)
		{
			cout << v[i];
			if (i + 1<v.size())
				cout << " * ";
		}
		cout << endl;
	}
	return 0;
}