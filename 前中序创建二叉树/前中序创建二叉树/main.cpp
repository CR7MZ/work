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
	//1.�õ������
	int root = pre[0];
	TreeNode* node = new TreeNode(root);

	//����������ҵ����ڵ���±�
	int PoMid = Find(post, root);

	//ͨ�������и��ڵ���±꣬�ó���������ǰ������
	vector<int> leftPre = Copy(pre, 1, PoMid);
	vector<int> leftPos = Copy(post, 0, PoMid - 1);
	node->left = buildTree(leftPre, leftPos);

	//ͨ�������и��ڵ���±꣬�ó���������ǰ������
	vector<int> rightPre = Copy(pre, PoMid + 1, pre.size() - 1);
	vector<int> rightPos = Copy(post, PoMid + 1, post.size() - 1);
	node->right = buildTree(rightPre, rightPos);

	return node;
}