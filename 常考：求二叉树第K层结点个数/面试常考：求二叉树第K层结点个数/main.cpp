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

//�ݹ�ⷨO(N)
//˼·�������rootΪ���ڵ�ĵ�K������������൱�������root������Ϊ���ĵ�K-1��Ľ���������root���Һ���Ϊ���ĵ�K-1��Ľ�����֮�͡�
//1.�����Ϊ�ջ���K<1������0
//2.�������Ϊ����K==1������1
//3.�������Ϊ����k>1������root�������е�k-1������root���Һ����е�k-1����֮�͡�

int getKlevelNum(TreeNode* root,int k)
{
	if (root == nullptr && k < 1)
		return 0;
	if (k == 1)
		return 1;
	return getKlevelNum(root->left, k - 1) + getKlevelNum(root->right, k - 1);
}