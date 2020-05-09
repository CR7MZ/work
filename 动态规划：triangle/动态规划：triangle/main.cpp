#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��Ŀ:https://www.nowcoder.com/questionTerminal/2b7995aa4f7949d99674d975489cb7da
//��Ϊ���������
//һ�������ʱ��һ����Ϊ����ߵĽ�㣬��ô�ض�ֻ���Ǵ���һ�������߽�������ģ�Ҳ����array[i - 1][0]
//���������ʱ��һ����Ϊ���ұߵĽ�㣬��ô�ض�ֻ���Ǵ���һ������ұ߽�������ģ�Ҳ����array[i - 1][j-1]
//���������ʱ��һ����Ϊ�м��㣬��ôÿ���ڵ��п��ܴ�����һ���ǰһ����㣨array[i - 1][j - 1]����
//����һ��������㣨array[i - 1][j]�������ģ�����Ҫ��������С��һ����
//ȫ�����������һ��Ϊ����·����������Сֵ��ѡ����������С�ļ��ɡ�

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