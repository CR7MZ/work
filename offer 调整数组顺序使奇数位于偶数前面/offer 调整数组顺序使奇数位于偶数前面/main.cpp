//��Ŀ��https://www.nowcoder.com/questionTerminal/beb5aa231adc45b2a5dcc5b62c93f593?f=discussion
#include<iostream>
#include<vector>
//˼·������һ����������ż�����������飬����ż����������������У����ҽ����ԭ������ɾ������������������ż���ֿ����������λ�ò��䡣
//�������ż������ԭ�����С�
void reOrderArray(std::vector<int> &array) {
	int size = array.size();
	std::vector<int> tmp;
	auto it = array.begin();
	while (it != array.end())
	{
		if ((*it) % 2 == 0)
		{
			tmp.push_back(*it);
			it = array.erase(it);
		}
		else
			it++;
	}
	for (auto e : tmp)
	{
		array.push_back(e);
	}
}