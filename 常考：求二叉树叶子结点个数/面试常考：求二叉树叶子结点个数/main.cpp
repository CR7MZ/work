#include <iostream>
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

//递归解法
//1.二叉树为空，返回0
//2.二叉树为叶子结点，返回1
//3.二叉树不为叶子结点，叶子结点 = 左子树叶子结点 + 右子树叶子结点
int GetNodeLeafNum1(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr || root->right == nullptr)
		return 1;

	return GetNodeLeafNum1(root->left) + GetNodeLeafNum1(root->right);
}

//非递归解法
//使用层序遍历，遍历每一个结点
int GetNodeLeafNum2(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	int count = 0;
	queue<TreeNode*> q;
	TreeNode* cur = nullptr;
	q.push(root);
	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++)
		{
			cur = q.front();
			if (cur->left == nullptr&&cur->right == nullptr)
				++count;

			if (cur->left)
				q.push(cur->left);

			if (cur->right)
				q.push(cur->right);
			
			q.pop();
		}
	}
	return count;
}