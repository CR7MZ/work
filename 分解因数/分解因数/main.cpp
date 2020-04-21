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
			while (n%i == 0)//���������Ϊ0����˵����һ��������������������
			{
				if (n != 1)//�ҵ�һ���������ͽ��������
				{
					v.push_back(i);
					n /= i;
				}
			}
		}
		if (n != 1)//������n��Ϊ1˵����Ϊ���һ������
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