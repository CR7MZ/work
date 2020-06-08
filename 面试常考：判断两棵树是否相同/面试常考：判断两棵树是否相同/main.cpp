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
//1.��������Ϊ�գ�����true
//2.һ����Ϊ�գ�һ����Ϊ�գ�����false
//3.��������Ϊ�գ������Ӧ����(��)��������(��)��������ͬ����ô�򷵻�true
bool IsSame1(TreeNode* t1, TreeNode* t2)
{
	if (t1 == nullptr&&t2 == nullptr)
		return true;
	if (t1 == nullptr || t2 == nullptr)
		return false;
	if (t1->val != t2->val)
		return false;

	return IsSame1(t1->left, t2->left)&IsSame1(t1->right, t2->right);
}


//�ǵݹ�ⷨ
//ʹ�ò������������ÿһ�����

bool IsSame2(TreeNode* t1, TreeNode* t2)
{
	if (t1 == nullptr && t2 == nullptr)
		return true;
	else if (t1 == nullptr || t2 == nullptr)
		return false;

	queue<TreeNode*> q1;
	queue<TreeNode*> q2;
	TreeNode* cur1 = nullptr;
	TreeNode* cur2 = nullptr;
	q1.push(t1);
	q2.push(t2);

	while (!q1.empty() && !q2.empty())
	{
		cur1 = q1.front();
		cur2 = q2.front();
		q1.pop();
		q2.pop();
		if (cur1 == nullptr && cur2 == nullptr)
			continue;
		else if (cur1 != nullptr && cur2 != nullptr && cur1->val == cur2->val)
		{
			q1.push(cur1->left);
			q1.push(cur1->right);
			q2.push(cur2->left);
			q2.push(cur2->right);
		}
		else
			return false;
	}
	return true;
}