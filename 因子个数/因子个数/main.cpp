#include <iostream>
#include <math.h>
using namespace std;

//https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 2; i<sqrt(n); i++)
		{
			if (n%i == 0)
				count++;
			while (n%i == 0)//�ҵ�һ�������ͽ��������������֮��Ͳ����ظ�������
			{
				n /= i;
			}
		}
		if (n != 1)count += 1;
		cout << count << endl;
	}
	return 0;
}