//题目：https://leetcode-cn.com/problems/subsets/submissions/
#include<iostream>
#include<vector>
//将数组中的数字一次挨个加入到前面得到的所有的子集中，即可得到全部的子集。
std::vector<std::vector<int>> subsets(std::vector<int>& nums)
{
	std::vector<std::vector<int>> res;//保存返回的所有子集

	std::vector<int> tmp;//保存之前的子集，用于将数字加入到子集中形成新的子集，再放入res中。

	res.push_back(tmp);//先插入一个空子集。

	for (int i = 0; i < nums.size(); i++)//循环对数组中给出的数字，进行形成新子集的操作
	{
		int num = res.size();//记录此时保存了多少个元素，要将新加入的元素，一次加入到之前的子集中，形成新的子集
		for (int j = 0; j < num; j++)
		{
			tmp = res[j];//将之前的子集保存到tmp 中

			tmp.push_back(nums[i]);//将新数字插入到tmp中

			res.push_back(tmp);//最后把新子集，放回子集数组中。

		}
	}
	return res;
}
int main()
{
	std::vector<int> I = { 1, 2, 3 };
	std::vector<std::vector<int>> v;
	v = subsets(I);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			std::cout << v[i][j] << " ";
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}