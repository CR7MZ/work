#include<iostream>
using namespace std;
#include<vector>
//��Ŀ��https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/submissions/

//�ö�ά�����е�һ������С��������һ��������ߣ�����������һ�������±ߡ���ˣ������Ͻǿ�ʼ���ң�
//�Ϳ��Ը��� n �͵�ǰԪ�صĴ�С��ϵ����С�������䣬��ǰԪ�صĲ�������Ϊ���½ǵ�����Ԫ�ء�
 bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        int tmp = matrix[i][j];
        while(i < m && j >= 0)
        {
            tmp = matrix[i][j];
            if (tmp > target){
                j--;
            }else if (tmp < target){
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
