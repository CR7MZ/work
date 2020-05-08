#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//��Ŀ��https://www.nowcoder.com/questionTerminal/23462ed010024fcabb7dbd3df57c715e?f=discussion
//״̬���̣�F(i,j) = F(i-1,j) + F(i,j-1);       �����ĳһ��λ�ã�ֻ�ܴӸ�λ���Ϸ������󷽹������������Ҫ֪�������λ�õ���С��
//                                              ����֪�������λ���Ϸ�λ�õ����֣��Լ������λ������Ǹ�λ�õ����֣�����֮�����Сֵ
//                                              �����ϸ�λ�õ����֣���Ϊ��С����

//��ʼ����v[0][j]����һ�У���v[i][0]����һ�У���ֻ�ܴ�ǰ����ߣ��У��������棨�У��߹��������ֻ��Ҫ
//    �У�v[0][j] = v[0][j - 1] + v[0][j];      �У�v[i][0] = v[i - 1][0] + v[i][0];

//����ֵ��v[row - 1][col - 1]
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> v(grid);
		for (int i = 1; i<row; i++)
		{
			v[i][0] = v[i - 1][0] + v[i][0];
		}

		for (int i = 1; i<col; i++)
		{
			v[0][i] = v[0][i - 1] + v[0][i];
		}
		for (int i = 1; i<row; i++)
		{
			for (int j = 1; j<col; j++)
			{
				v[i][j] = min(v[i - 1][j], v[i][j - 1]) + v[i][j];
			}
		}
		return v[row - 1][col - 1];
	}
};