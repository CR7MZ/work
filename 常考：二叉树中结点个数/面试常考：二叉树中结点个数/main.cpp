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
		,left(nullptr)
		,right(nullptr)
	{}
};

int GetNodeNum1(TreeNode* root)//递归实现
{
	if (root == nullptr)
		return 0;

	return GetNodeNum1(root->left) + GetNodeNum1(root->right) + 1;
}

int GetNodeNum2(TreeNode* root)//非递归,相当于层序遍历
{
	if (root == nullptr)
		return 0;

	int count = 1;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* cur = q.front();
		if (cur->left)
		{
			q.push(cur->left);
			++count;
		}
		if (cur->right)
		{
			q.push(cur->right);
			++count;
		}
		q.pop();
	}
	return count;
}