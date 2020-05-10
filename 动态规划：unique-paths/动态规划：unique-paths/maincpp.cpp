#include <iostream>
#include <vector>
using namespace std;

//��Ŀ��https://www.nowcoder.com/questionTerminal/166eaff8439d4cd898e3ba933fbc6358
//״̬���̣�F(i,j)=F(i-1,j)+F(i,j-1); ��ΪҪ����F(i,j)����㣬��ôֻ�ܴ�F(i-1,j)������ ���� F(i,j-1)�����ߣ�
//                                    ����������Ҫ֪�������������ж������߷���������ӾͿ���֪���ִ�F(i,j)�ܹ����߷���

//��ʼ����F(0,j)=1,F(i,0)=1;          ��ΪҪ�����������������ڵ��������ϵ�����һ��λ��ֻ��һ��·����
//����ֵ��v[m - 1][n - 1]

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