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

//递归解法O(N)
//思路：求出以root为根节点的第K层结点个数，就相当于求出以root的左孩子为根的第K-1层的结点个数与以root的右孩子为根的第K-1层的结点个数之和。
//1.如果树为空或者K<1，返回0
//2.如果树不为空且K==1，返回1
//3.如果树不为空且k>1，返回root的左孩子中第k-1层结点与root的右孩子中第k-1层结点之和。

int getKlevelNum(TreeNode* root,int k)
{
	if (root == nullptr && k < 1)
		return 0;
	if (k == 1)
		return 1;
	return getKlevelNum(root->left, k - 1) + getKlevelNum(root->right, k - 1);
}