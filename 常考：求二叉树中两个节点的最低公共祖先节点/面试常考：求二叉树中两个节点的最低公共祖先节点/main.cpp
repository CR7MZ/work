#include <iostream>

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

//递归解法：
//1.如果两个结点分别在根结点的左子树和右子树，那么返回根结点即可。
//2.如果两个结点都在根结点的左子树或者右子树，那么递归处理左子树或者右子树。

bool IsInTree(TreeNode* root,TreeNode* cur)//判断一个结点是否在树中。
{
	if (root == nullptr || cur == nullptr)
		return false;
	if (root == cur)
		return true;
	
	bool res = IsInTree(root->left, cur);
	if (!res)
	{
		res = IsInTree(root->right, cur);
	}
	return res;
}

TreeNode* GetCommonParent(TreeNode* root, TreeNode* t1, TreeNode* t2)
{
	if (root == nullptr)
		return nullptr;

	if (IsInTree(root->left, t1))//如果n1在左子树中
	{
		if (IsInTree(root->right, t2))//如果n2在右子树这种，则返回root
		{
			return root;
		}
		else                      //如果n2在左子树中，递归遍历左子树
		{
			return GetCommonParent(root->left, t1, t2);
		}
	}
	else                             //如果n1在右子树中
	{
		if (IsInTree(root->left, t2))//如果n2在左子树这种，则返回root
		{
			return root;
		}
		else                         //如果n2在右子树中，递归遍历右子树
		{
			return GetCommonParent(root->right, t1, t2);
		}
	}
	return nullptr;
}