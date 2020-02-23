//题目：https://www.nowcoder.com/questionTerminal/390da4f7a00f44bea7c2f3d19491311b?f=discussion
#include<iostream>
#include<vector>

//思路：
//1.因为是递增的。
//2.定义两个指向头尾的指针。
//3.若array[i] + array[j] == sum，得到两个数，因为最远端的两个数成绩最小。
//4.若array[i] + array[j] <  sum，说明小了，左边坐标++。
//5.若array[i] + array[j] >  sum，说明大了，右边坐标--。
std::vector<int> FindNumbersWithSum(std::vector<int> array, int sum) {
	std::vector<int> res;
	int i = 0;
	int j = array.size() - 1;
	while (i<j)
	{
		if (array[i] + array[j] == sum)
		{
			res.push_back(array[i]);
			res.push_back(array[j]);
			break;
		}
		else if (array[i] + array[j]>sum)
			j--;
		else
			i++;
	}
	return res;
}