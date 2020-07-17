#include<iostream>
using namespace std;
#include<vector>
//题目：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/submissions/

//该二维数组中的一个数，小于它的数一定在其左边，大于它的数一定在其下边。因此，从右上角开始查找，
//就可以根据 n 和当前元素的大小关系来缩小查找区间，当前元素的查找区间为左下角的所有元素。
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
