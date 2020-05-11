#include <iostream>
#include <vector>
using namespace std;

//��Ŀ��https://www.nowcoder.com/questionTerminal/3cdf08dd4e974260921b712f0a5c8752
//״̬���̣�F(i,j)=F(i-1,j)+F(i,j-1); 

//��ʼ�����ڵ�0�л��0���У��������һ��λ����ֵΪ1(�������谭)����ô��һ�л���һ���д����λ�ÿ�ʼ(�������λ��)�Ժ��λ�ö�����ִ�
//        ����֮�⣬��һ�л�һ��������λ�ö����Եִ
//����ֵ��v[m - 1][n - 1]

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
				if (obstacleGrid[i][j] == 0) //ԭ������Ϊ0˵��û���谭�����Եִ�������λ�����谭�����ɵ��
					v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[row - 1][col - 1];
	}
};