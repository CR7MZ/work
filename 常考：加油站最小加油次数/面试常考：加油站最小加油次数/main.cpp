#include <iostream>
#include <queue>
using namespace std;

//题目及解析：https://blog.csdn.net/qzq2514/article/details/56504059
//n个加油站、一共行驶l距离、最初油缸油量为p

int Slove(vector<int>& A,vector<int>& B,int p,int n)
{
	//ans:加油次数 pos:当前距离起始位置  tank:油缸油量
	int ans = 0, pos = 0, tank = p;

	//pq存放的是之前通过各个加油站所加的油。（注意加油站加的油放在后备箱，并不会直接加入油缸）
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < n; i++)
	{
		int Dist = A[i] - pos;

		//油缸中剩余油量无法抵达下一个加油站，需要加油
		if (Dist > tank)
		{
			//若后备箱也没有油则无法抵达。
			while (!pq.empty())
			{
				//无法抵达
				return -1;
			}
			pair<int, int> tmp = pq.top();
			pq.pop();
			tank += tmp.first;
			++ans;
		}

		//油缸中油量够，计算抵达下一个加油站，剩余油量
		tank -= Dist;

		//更新pos，记录此时相对于初始位置的距离。
		pos = A[i];

		//将当前加油站，该哪上的油放入后备箱。
		pq.push(make_pair(B[i], i));
	}
	return ans;
}