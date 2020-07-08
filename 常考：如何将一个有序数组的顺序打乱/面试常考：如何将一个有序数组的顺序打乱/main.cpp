#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

//O(N^2) 辅助空间为N
//创建一个新的数组保存打乱的变量。
//随机产生一个随机数，将其当做原数组的下标找到对应下标的值放入新的数组中。
//并将该值从原住宿中删除掉。
void Func1(vector<int>& vec)
{
	int j = 0,size = vec.size();
	vector<int> tmp(vec.size(), 0);
	srand((unsigned)time(NULL));   //初始化随机种子，就解决每次产生随机数一样的问题。

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

//O(N) 辅助空间为1
//循环遍历数组，每次循环产生一个0 - size-1的随机数
//将本次循环的位置和随机数为上的数字进行交换。
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