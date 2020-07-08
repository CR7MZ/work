#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

//O(N^2) �����ռ�ΪN
//����һ���µ����鱣����ҵı�����
//�������һ������������䵱��ԭ������±��ҵ���Ӧ�±��ֵ�����µ������С�
//������ֵ��ԭס����ɾ������
void Func1(vector<int>& vec)
{
	int j = 0,size = vec.size();
	vector<int> tmp(vec.size(), 0);
	srand((unsigned)time(NULL));   //��ʼ��������ӣ��ͽ��ÿ�β��������һ�������⡣

	while (size)
	{
		int index = rand()%size;
		tmp[j++] = vec[index];
		for (int i = index; i < size - 1; i++)
		{
			vec[i] = vec[i + 1];
		}
		--size;
	}
	vec = tmp;
}

//O(N) �����ռ�Ϊ1
//ѭ���������飬ÿ��ѭ������һ��0 - size-1�������
//������ѭ����λ�ú������Ϊ�ϵ����ֽ��н�����
void Func2(vector<int>& vec)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < vec.size(); i++)
	{
		int index = rand() % vec.size();
		if (index == i)
			continue;
		swap(vec[i], vec[index]);
	}
}
int main()
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	Func2(v);
	return 0;
}