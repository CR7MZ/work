//题目：https://www.nowcoder.com/questionTerminal/435fb86331474282a3499955f0a41e8b?f=discussion
#include<iostream>
#include<queue>
#include<algorithm>
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
//思路：
//如果该树只有一个根节点，那么深度为1。如果该树只有左子树，该树的深度为左子树的深度+1。
//如果该树只有右子树，该树的深度为右子树的深度+1。
//如果该树有左子树也有右子树，深度为左子树和右子树的最大值+1。
//递归：
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	return std::max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}

//思想：
//层序遍历，遍历一层，深度+1。
//循环：
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	std::queue<TreeNode*> q;
	q.push(pRoot);
	int res = 0;
	while (!q.empty())
	{
		int size = q.size();
		res++;
		for (int i = 0; i<size; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
	}
	return  res;
}