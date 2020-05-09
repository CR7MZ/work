#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//题目:https://www.nowcoder.com/questionTerminal/2b7995aa4f7949d99674d975489cb7da
//分为三这种情况
//一：如果此时这一层结点为最左边的结点，那么必定只能是从上一层的最左边结点下来的，也就是array[i - 1][0]
//二：如果此时这一层结点为最右边的结点，那么必定只能是从上一层的最右边结点下来的，也就是array[i - 1][j-1]
//三：如果此时这一层结点为中间结点，那么每各节点有可能从上面一层的前一个结点（array[i - 1][j - 1]）和
//上面一层的这个结点（array[i - 1][j]）下来的，我们要求其中最小的一个。
//全部结束后，最后一行为所有路径下来的最小值，选出其中做最小的即可。

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {

		vector<vector<int>> array(triangle);
		int row = triangle.size();
		for (int i = 1; i<row; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
					array[i][j] = array[i - 1][j] + triangle[i][j];
				else if (j == i)
					array[i][j] = array[i - 1][j - 1] + triangle[i][j];
				else
					array[i][j] = min(array[i - 1][j - 1], array[i - 1][j]) + triangle[i][j];
			}
		}
		int res = array[row - 1][0];
		for (int i = 1; i<row; i++)
		{
			res = min(res, array[row - 1][i]);
		}
		return res;
	}
};