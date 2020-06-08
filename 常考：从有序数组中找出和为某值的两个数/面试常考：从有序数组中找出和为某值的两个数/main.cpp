#include <iostream>
#include <vector>

using namespace std;

//˼·��������ŵ�˼�룬��������Ϊ���򣬶�������ָ�룬һ��ָ��ͷlow��һ��ָ��β��hight������ߵĺ�Ϊtmp 
//���tmp > k����ô˵�����ˣ�hight--������ߵĺ�Ϊtmp 
//���tmp < k����ô˵��С�ˣ�low++������ߵĺ�Ϊtmp 
//���tmp == k��˵���ҵ�������������
void Func(const vector<int>& vec, int& x, int& y,int k)
{
	int low = 0, hight = vec.size() - 1;
	int tmp = vec[low] + vec[hight];
	while (low < hight && tmp != k)
	{
		while (low < hight && tmp < k)
		{
			++low;
			tmp = vec[low] + vec[hight];
		}
		while (low < hight && tmp > k)
		{
			--hight;
			tmp = vec[low] + vec[hight];
		}
	}
	if (tmp == k)
	{
		x = vec[low];
		y = vec[hight];
	}
	else
	{
		x = 0;
		y = 0;
	}
}

int main()
{
	vector<int> v = { 1, 20, 23, 58, 60 };
	int x, y, k;
	cin >> k;
	Func(v, x, y, k);
	return 0;
}