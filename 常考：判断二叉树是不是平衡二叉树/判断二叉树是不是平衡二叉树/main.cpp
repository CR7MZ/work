#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x)
		, left(nullptr)
		, right(nullptr)
	{}
};

int TreeHigh(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	return max(TreeHigh(root->left) ,TreeHigh(root->right)) + 1;
}

//递归解决
//1.如果为空，则返回true
//2.如果不为空，如果左子树和右子树都为AVL树且左右子树高度只差不大于1。返回真，其他返回假
bool IsAVLTree(TreeNode* root)
{
	if (root == nullptr)
		return true;
	if (abs(TreeHigh(root->left) - TreeHigh(root->right)) > 1)
	{
		return false;
	}
	return IsAVLTree(root->left) && IsAVLTree(root->right);
}