//��Ŀ��https://www.nowcoder.com/questionTerminal/9b4c81a02cd34f76be2659fa0d54342a?f=discussion
//��ϸ������https://blog.csdn.net/CR7lmz/article/details/104146334
#include<iostream>
#include<vector>
using namespace std;
//˼·�������ĸ�����left��top��right��butt���涨���ε����ϡ��ҡ��±߽硣
//��ӡ��һȦ�����ݣ���һȦ���ݴ�ӡ�������ĸ�����ֱ�ǰ������һλ��������ӡ��һ�㡣
vector<int> printMatrix(vector<vector<int> > matrix) {
	int left = 0, top = 0, butt = matrix.size() - 1, right = matrix[0].size() - 1;
	vector<int> v;
	while (left <= right&&top <= butt)
	{
		for (int i = left; i <= right; i++)
			v.push_back(matrix[top][i]);
		for (int i = top + 1; i <= butt; i++)
			v.push_back(matrix[i][right]);
		if (top != butt)                           //���top��butt����ˣ��Ͳ��ܽ��д�������Ĵ�ӡ��������ظ���ӡ��
			for (int i = right - 1; i >= left; i--)
				v.push_back(matrix[butt][i]);
		if (left != right)                         //���left��right����ˣ��Ͳ��ܽ��д������ϵĴ�ӡ��������ظ���ӡ��
			for (int i = butt - 1; i>top; i--)
				v.push_back(matrix[i][left]);
		left++; top++; right--; butt--;
	}
	return v;
}