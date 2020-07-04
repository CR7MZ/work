#include <iostream>
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
//1.������Ϊ�գ�����0
//2.������ΪҶ�ӽ�㣬����1
//3.��������ΪҶ�ӽ�㣬Ҷ�ӽ�� = ������Ҷ�ӽ�� + ������Ҷ�ӽ��
int GetNodeLeafNum1(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr || root->right == nullptr)
		return 1;

	return GetNodeLeafNum1(root->left) + GetNodeLeafNum1(root->right);
}

//�ǵݹ�ⷨ
//ʹ�ò������������ÿһ�����
int GetNodeLeafNum2(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	int count = 0;
	queue<TreeNode*> q;
	TreeNode* cur = nullptr;
	q.push(root);
	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++)
		{
			cur = q.front();
			if (cur->left == nullptr&&cur->right == nullptr)
				++count;

			if (cur->left)
				q.push(cur->left);

			if (cur->right)
				q.push(cur->right);
			
			q.pop();
		}
	}
	return count;
}