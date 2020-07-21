#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

//1.用unordered_map统计所有数字出现的次数
//2.用priority_queue找出出现次数为前K个元素
vector<int> TopK(vector<int>& vec , int k)
{
	vector<int> res;
	//定义一个unordered_map统计每个数字出现的次数
	unordered_map<char,int> um;

	for (auto e : vec)
	{
		um[e]++;
	}

	//定义一个priority_queue来获得Topk
	priority_queue<pair<int, char>> pq;
	for (auto it = um.begin(); it != um.end(); ++it)
	{
		pq.push(make_pair(it->second, it->first));

		//当pq中的元素个数大于um中元素个数-k，那么说明次数pq中必定有前k个元素里其中一个
		if (pq.size() > um.size() - k)
		{
			res.push_back(pq.top().second);
			pq.pop();
		}	
	}
	return res;
}

int main()
{
	vector<int> v = { 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
	vector<int> res = TopK(v, 3);
	return 0;
}