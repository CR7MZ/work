//题目：https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd?f=discussion
#include<iostream>
#include<vector>
//递归：
//由题目得到，因为是后序遍历，所以序列最后一个元素一定是树的根root。又因为是二叉搜索树，所以左子树所有的值小于root，右子树所有的值
//大于root
//1.先找到root，记录上。
//2.遍历序列找到第一个大于root的值的下标，同时将之前的所有值放入数组left中。这个坐标左边是左子树，右边是右子树。
//3.遍历右子树，同时将右子树放入数组right中。若有小于root对的值，直接返回false。
//4.分别判断左右子树是不是二叉搜索树，循环1、2、3步骤。
bool VerifySquenceOfBST(std::vector<int> sequence)
{
	if (sequence.empty())//仅用于判断总序列是否为空。
		return false;
	std::vector<int> left, right;
	int size = sequence.size();
	int i = 0;
	int root = sequence[size - 1];
	for (; i < size - 1; i++)
	{
		if (sequence[i] < root)
			left.push_back(sequence[i]);
		else
			break;
	}
	for (int j = i; j < size - 1; j++)
	{
		if (sequence[j] > root)
			right.push_back(sequence[j]);
		else
			return false;
	}	
	bool le = true, ri = true; //因为总序列不为空，因此左右子树为空也是二叉搜索树，不用进行递归。所以代表左子树le和右子树ri初始化为true。
	if (!left.empty())
		le = VerifySquenceOfBST(left);
	if (!right.empty())
		ri = VerifySquenceOfBST(right);
	return le&&ri;
}

//非递归：
bool VerifySquenceOfBST2(std::vector<int> sequence)
{
	int size = sequence.size();
	if (0 == size) return false;

	int i = 0;
	while (--size){
		while (sequence[i++] < sequence[size]);
		while (sequence[i++] > sequence[size]);

		if (i < size) return false;

		i = 0;
	}

	return true;
}