#include <iostream>
#include <vector>
using namespace std;

//题目：https://www.nowcoder.com/questionTerminal/166eaff8439d4cd898e3ba933fbc6358
//状态方程：F(i,j)=F(i-1,j)+F(i,j-1); 因为要到达F(i,j)这个点，那么只能从F(i-1,j)想下走 或者 F(i,j-1)向右走，
//                                    所以我们需要知道到达这两点有多少种走法，将其相加就可以知道抵达F(i,j)总共的走法。

//初始化：F(0,j)=1,F(i,0)=1;          因为要到达矩形中与起点相邻的两条边上的任意一个位置只有一条路径。
//返回值：v[m - 1][n - 1]

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> v(m, vector<int>(n, 1));
		for (int i = 1; i<m; i++)
		{
			for (int j = 1; j<n; j++)
			{
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[m - 1][n - 1];
	}
};