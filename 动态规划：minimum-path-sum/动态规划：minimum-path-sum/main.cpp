#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//题目：https://www.nowcoder.com/questionTerminal/23462ed010024fcabb7dbd3df57c715e?f=discussion
//状态方程：F(i,j) = F(i-1,j) + F(i,j-1);       表格中某一个位置，只能从该位置上方或者左方过来，因此我们要知道到达该位置的最小数
//                                              必须知道到达该位置上方位置的数字，以及到达该位置左边那个位置的数字，二者之间的最小值
//                                              最后加上该位置的数字，即为最小数字

//初始化：v[0][j]（第一行）或v[i][0]（第一列），只能从前面左边（行）或者上面（列）走过来，因此只需要
//    行：v[0][j] = v[0][j - 1] + v[0][j];      列：v[i][0] = v[i - 1][0] + v[i][0];

//返回值：v[row - 1][col - 1]
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