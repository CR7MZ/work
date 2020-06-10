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

//递归解法
//1.如果树为空，高度为0
//2.不为空，高度为max(左子树深度，柚子树深度) + 1

int TreeHigh1(TreeNode*& root)
{
	if (root == nullptr)
		return 0;
	return max(TreeHigh1(root->left), TreeHigh1(root->right)) + 1;
}


//非递归解法
//使用层序遍历
int maxDepth(TreeNode* root) {
	if (root == nullptr)
		return 0;

	int dep = 0, levelcount = 0;//dep树的高度，levelcount每一层结点个数
	TreeNode* cur = nullptr;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		levelcount = q.size();
		for (int i = 0; i < levelcount; i++)//处理这一层的结点
		{
			cur = q.front();
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
			q.pop();
		}
		++dep;//每处理完一层，高度+1。
	}
	return dep;
}