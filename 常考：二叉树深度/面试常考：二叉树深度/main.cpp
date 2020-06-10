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

//�ݹ�ⷨ
//1.�����Ϊ�գ��߶�Ϊ0
//2.��Ϊ�գ��߶�Ϊmax(��������ȣ����������) + 1

int TreeHigh1(TreeNode*& root)
{
	if (root == nullptr)
		return 0;
	return max(TreeHigh1(root->left), TreeHigh1(root->right)) + 1;
}


//�ǵݹ�ⷨ
//ʹ�ò������
int maxDepth(TreeNode* root) {
	if (root == nullptr)
		return 0;

	int dep = 0, levelcount = 0;//dep���ĸ߶ȣ�levelcountÿһ�������
	TreeNode* cur = nullptr;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		levelcount = q.size();
		for (int i = 0; i < levelcount; i++)//������һ��Ľ��
		{
			cur = q.front();
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
			q.pop();
		}
		++dep;//ÿ������һ�㣬�߶�+1��
	}
	return dep;
}