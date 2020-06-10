#include <iostream>
#include <queue>
using namespace std;

//��Ŀ��������https://blog.csdn.net/qzq2514/article/details/56504059
//n������վ��һ����ʻl���롢����͸�����Ϊp

int Slove(vector<int>& A,vector<int>& B,int p,int n)
{
	//ans:���ʹ��� pos:��ǰ������ʼλ��  tank:�͸�����
	int ans = 0, pos = 0, tank = p;

	//pq��ŵ���֮ǰͨ����������վ���ӵ��͡���ע�����վ�ӵ��ͷ��ں��䣬������ֱ�Ӽ����͸ף�
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < n; i++)
	{
		int Dist = A[i] - pos;

		//�͸���ʣ�������޷��ִ���һ������վ����Ҫ����
		if (Dist > tank)
		{
			//������Ҳû�������޷��ִ
			while (!pq.empty())
			{
				//�޷��ִ�
				return -1;
			}
			pair<int, int> tmp = pq.top();
			pq.pop();
			tank += tmp.first;
			++ans;
		}

		//�͸���������������ִ���һ������վ��ʣ������
		tank -= Dist;

		//����pos����¼��ʱ����ڳ�ʼλ�õľ��롣
		pos = A[i];

		//����ǰ����վ�������ϵ��ͷ�����䡣
		pq.push(make_pair(B[i], i));
	}
	return ans;
}