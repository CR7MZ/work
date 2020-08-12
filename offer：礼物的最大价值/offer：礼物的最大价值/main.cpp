#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//题目：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
//因为每一个位置只能从上面或者左面选择，因此需要从上面和左面找出最大值，统计起来，最终记录在当前位置，用于下次选择
//但是需要处理边界数据，因此需要创建新的二维数组比原数组多一行多一列，用来初始化边界数据
int maxValue(vector<vector<int>>& grid) {
	vector<vector<int>> v(grid.size() + 1, vector<int>(grid[0].size() + 1));
	for (int i = 1; i < v.size(); i++){
		for (int j = 1; j < v[0].size(); j++){
				v[i][j] = max(v[i - 1][j], v[i][j - 1]) + grid[i - 1][j - 1];
		}
	}
	return v[v.size() - 1][v[0].size() - 1];
}