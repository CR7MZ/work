//题目：https://www.nowcoder.com/questionTerminal/b736e784e3e34731af99065031301bca?f=discussion
#include<iostream>
#include<vector>
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

//思路：
//通过递归遍历每一个节点（先遍历左，再遍历右）。每遍历一个节点将其值放入tmp中，并用总值减去目前节点的值，来当做遍历下一个的总值。
//若找到叶子结点并且此时结点的值等于此时的总值，说明一条路径已经找到，将此路径返回给res即可。否则继续遍历左右子树
//当找到一条路径后，需删除tmp中最后一节点，再继续找其他路径。
//当遍历到叶子节点，但是此条路径不满足条件，删除tmp最后一个元素。另找其他路。

std::vector<std::vector<int>> res;//因为要记录所有路径，所以需要定义一个二维数组来保存所有路径。
                                 //又因为需要递归来找到所有路径，因此将其设为全局变量。

std::vector<int> tmp;//保存每一条路径的所有节点值。
void find(TreeNode* root, int expectNumber)
{
	if (root == nullptr)
		return;
	tmp.push_back(root->val);
	if (!root->left&&!root->right&&root->val == expectNumber)
		res.push_back(tmp);
	else
	{
		if (root->left)
			find(root->left, expectNumber - root->val);
		if (root->right)
			find(root->right, expectNumber - root->val);
	}
	tmp.pop_back();
}
std::vector<std::vector<int> > FindPath(TreeNode* root, int expectNumber) {
	find(root, expectNumber);
	return res;
}