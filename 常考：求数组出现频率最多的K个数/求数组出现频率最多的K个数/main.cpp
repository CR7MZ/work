#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

//1.��unordered_mapͳ���������ֳ��ֵĴ���
//2.��priority_queue�ҳ����ִ���ΪǰK��Ԫ��
vector<int> TopK(vector<int>& vec , int k)
{
	vector<int> res;
	//����һ��unordered_mapͳ��ÿ�����ֳ��ֵĴ���
	unordered_map<char,int> um;

	for (auto e : vec)
	{
		um[e]++;
	}

	//����һ��priority_queue�����Topk
	priority_queue<pair<int, char>> pq;
	for (auto it = um.begin(); it != um.end(); ++it)
	{
		pq.push(make_pair(it->second, it->first));

		//��pq�е�Ԫ�ظ�������um��Ԫ�ظ���-k����ô˵������pq�бض���ǰk��Ԫ��������һ��
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