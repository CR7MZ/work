#include <iostream>
#include <vector>

using namespace std;

//思路：借鉴快排的思想，由于数组为升序，定义两个指针，一个指向开头low，一个指向尾部hight。求二者的和为tmp 
//如果tmp > k，那么说明大了，hight--。求二者的和为tmp 
//如果tmp < k，那么说明小了，low++。求二者的和为tmp 
//如果tmp == k，说明找到，返回两个数
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