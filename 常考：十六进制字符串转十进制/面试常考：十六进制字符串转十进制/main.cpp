#include <iostream>
#include <string>

using namespace std;

long long change_num(char* _str)
{
	string str(_str);
	long long res = 0;
	long long count = 1;

	for (int i = str.size() - 1; i >= 0; i--)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			res += ((str[i] - '0') * count);
		}
		else if ((str[i] >= 'a') && (str[i] <= 'f'))
		{
			//因为a、A代表10。
			//a=97 A=65
			res += ((str[i] - 'a' + 10) * count);    
		}
		else if ((str[i] >= 'A') && (str[i] <= 'F'))
		{
			res += ((str[i] - 'A' + 10) * count);
		}
		else
			continue;

		count *= 16;
	}
	return res;
}

int main()
{
	char* str = "0xA3";
	cout << change_num(str);
	return 0;
}