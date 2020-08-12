#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//��Ŀ��https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
//��Ϊÿһ��λ��ֻ�ܴ������������ѡ�������Ҫ������������ҳ����ֵ��ͳ�����������ռ�¼�ڵ�ǰλ�ã������´�ѡ��
//������Ҫ����߽����ݣ������Ҫ�����µĶ�ά�����ԭ�����һ�ж�һ�У�������ʼ���߽�����
int maxValue(vector<vector<int>>& grid) {
	vector<vector<int>> v(grid.size() + 1, vector<int>(grid[0].size() + 1));
	for (int i = 1; i < v.size(); i++){
		for (int j = 1; j < v[0].size(); j++){
				v[i][j] = max(v[i - 1][j], v[i][j - 1]) + grid[i - 1][j - 1];
		}
	}
	return v[v.size() - 1][v[0].size() - 1];
}