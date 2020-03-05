#include <iostream>
#include <vector>
using namespace std;

int Find(vector<int>& post, int res)
{
	for (int i = 0; i<post.size(); i++)
	{
		if (post[i] == res)
			return i;
	}
	return -1;
}
vector<int> Copy(const vector<int> res, int left, int right)
{
	vector<int> v;
	for (int i = left; i <= right; i++)
	{
		v.push_back(res[i]);
	}
	return v;
}
TreeNode* buildTree(vector<int>& pre, vector<int>& post) {
	if (pre.empty())
		return NULL;
	//1.得到根结点
	int root = pre[0];
	TreeNode* node = new TreeNode(root);

	//中序遍历中找到根节点的下标
	int PoMid = Find(post, root);

	//通过中序中根节点的下标，得出左子树的前序中序
	vector<int> leftPre = Copy(pre, 1, PoMid);
	vector<int> leftPos = Copy(post, 0, PoMid - 1);
	node->left = buildTree(leftPre, leftPos);

	//通过中序中根节点的下标，得出由子树的前序中序
	vector<int> rightPre = Copy(pre, PoMid + 1, pre.size() - 1);
	vector<int> rightPos = Copy(post, PoMid + 1, post.size() - 1);
	node->right = buildTree(rightPre, rightPos);

	return node;
}