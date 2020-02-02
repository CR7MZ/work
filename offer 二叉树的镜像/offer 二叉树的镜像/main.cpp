//题目：https://www.nowcoder.com/questionTerminal/564f4c26aa584921bc75623e48ca3011?f=discussion
#include<iostream>
//思路：
//要想得到树的镜像，只需用递归，对调二叉树中所有节点的左右指针域即可。
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x)
		:val(x)
		,left(nullptr)
		,right(nullptr)
	{}
};
void Mirror(TreeNode *pRoot) {
	if (pRoot == nullptr)
		return;
	if (pRoot->left == nullptr&&pRoot->right == nullptr)
		return;
	TreeNode* tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	Mirror(pRoot->left);
	Mirror(pRoot->right);
}