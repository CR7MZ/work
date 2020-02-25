//题目：https://www.nowcoder.com/questionTerminal/762836f4d43d43ca9deb273b3de8e1f4?f=discussion
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//大神思路：
//因为顺子只能有五张，并且0不可能放在首尾
//所以我们记住数组中一个最大的数。一个最小的数。如果二者只差>=5返回false。
bool IsContinuous(vector<int> numbers, int)
{
	if (numbers.size() != 5)
		return false;
	int min = 14;
	int max = -1;
	int flag = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		int num = numbers[i];
		if (num == 0)
			continue;
		if (((flag >> num) & 1) == 1)
			return false;
		flag |= (1 << num);
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		if (max - min >= 5)
			return false;
	}
	return true;
}



//个人思路：
//将数组中0计数，其他数字放到新数组res中，排序新数组，遍历res，用cur来统计res中每相邻两个数字之间隔了几个数
//如果cur为-1说明该数字重复出现了，返回false。否则用count来把cur保存起来，最后将count与0的个数相比较，0个数多则返回true。
bool IsContinuous(vector<int> numbers) {
	if (numbers.size() != 5)
		return false;
	vector<int> res;
	int tmp = 0;
	for (auto e : numbers)
	{
		if (e != 0)
			res.push_back(e);
		else if (e == 0)
			tmp++;
	}
	int count = 0;
	sort(res.begin(), res.end());
	for (int i = 0; i<res.size() - 1; i++)
	{
		int cur = res[i + 1] - res[i] - 1;
		if (cur == -1)
			return false;
		count += cur;
	}
	if (count>tmp)
		return false;
	return true;
}