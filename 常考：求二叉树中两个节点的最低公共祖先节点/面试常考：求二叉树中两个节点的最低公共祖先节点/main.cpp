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

//�ݹ�ⷨ��
//1.����������ֱ��ڸ�����������������������ô���ظ���㼴�ɡ�
//2.���������㶼�ڸ�������������������������ô�ݹ鴦��������������������

bool IsInTree(TreeNode* root,TreeNode* cur)//�ж�һ������Ƿ������С�
{
	if (root == nullptr || cur == nullptr)
		return false;
	if (root == cur)
		return true;
	
	bool res = IsInTree(root->left, cur);
	if (!res)
	{
		res = IsInTree(root->right, cur);
	}
	return res;
}

TreeNode* GetCommonParent(TreeNode* root, TreeNode* t1, TreeNode* t2)
{
	if (root == nullptr)
		return nullptr;

	if (IsInTree(root->left, t1))//���n1����������
	{
		if (IsInTree(root->right, t2))//���n2�����������֣��򷵻�root
		{
			return root;
		}
		else                      //���n2���������У��ݹ����������
		{
			return GetCommonParent(root->left, t1, t2);
		}
	}
	else                             //���n1����������
	{
		if (IsInTree(root->left, t2))//���n2�����������֣��򷵻�root
		{
			return root;
		}
		else                         //���n2���������У��ݹ����������
		{
			return GetCommonParent(root->right, t1, t2);
		}
	}
	return nullptr;
}