//题目：https://www.nowcoder.com/questionTerminal/9b4c81a02cd34f76be2659fa0d54342a?f=discussion
//详细解析：https://blog.csdn.net/CR7lmz/article/details/104146334
#include<iostream>
#include<vector>
using namespace std;
//思路：定义四个变量left、top、right、butt来规定矩形的左、上、右、下边界。
//打印第一圈的数据，当一圈数据打印结束后，四个变零分别前进后退一位，继续打印下一层。
vector<int> printMatrix(vector<vector<int> > matrix) {
	int left = 0, top = 0, butt = matrix.size() - 1, right = matrix[0].size() - 1;
	vector<int> v;
	while (left <= right&&top <= butt)
	{
		for (int i = left; i <= right; i++)
			v.push_back(matrix[top][i]);
		for (int i = top + 1; i <= butt; i++)
			v.push_back(matrix[i][right]);
		if (top != butt)                           //如果top和butt相等了，就不能进行从右向左的打印。会造成重复打印。
			for (int i = right - 1; i >= left; i--)
				v.push_back(matrix[butt][i]);
		if (left != right)                         //如果left和right相等了，就不能进行从下向上的打印。会造成重复打印。
			for (int i = butt - 1; i>top; i--)
				v.push_back(matrix[i][left]);
		left++; top++; right--; butt--;
	}
	return v;
}