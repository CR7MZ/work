//��Ŀ��https://www.nowcoder.com/questionTerminal/435fb86331474282a3499955f0a41e8b?f=discussion
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
//˼·��
//�������ֻ��һ�����ڵ㣬��ô���Ϊ1���������ֻ�������������������Ϊ�����������+1��
//�������ֻ�������������������Ϊ�����������+1��
//���������������Ҳ�������������Ϊ�������������������ֵ+1��
//�ݹ飺
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	return std::max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
}

//˼�룺
//�������������һ�㣬���+1��
//ѭ����
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