#include <iostream>
#include <vector>
using namespace std;

//题目：https://www.nowcoder.com/questionTerminal/3cdf08dd4e974260921b712f0a5c8752
//状态方程：F(i,j)=F(i-1,j)+F(i,j-1); 

//初始化：在第0行或第0列中，如果其中一个位置数值为1(代表有阻碍)，那么这一行或这一列中从这个位置开始(包括这个位置)以后的位置都不会抵达
//        除此之外，这一行或一列中其他位置都可以抵达。
//返回值：v[m - 1][n - 1]

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		vector<vector<int>> v(row, vector<int>(col, 0));

		for (int i = 0; i<row; i++)
		{
			if (obstacleGrid[i][0] == 0)
				v[i][0] = 1;
			else
				break;
		}

		for (int j = 0; j<col; j++)
		{
			if (obstacleGrid[0][j] == 0)
				v[0][j] = 1;
			else
				break;
		}

		for (int i = 1; i<row; i++)
		{
			for (int j = 1; j<col; j++)
			{
				if (obstacleGrid[i][j] == 0) //原数组中为0说明没有阻碍，可以抵达。否则，这个位置有阻碍，不可到达。
					v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[row - 1][col - 1];
	}
};