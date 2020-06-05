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

//�ݹ���
//1.���Ϊ�գ��򷵻�true
//2.�����Ϊ�գ��������������������ΪAVL�������������߶�ֻ�����1�������棬�������ؼ�
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