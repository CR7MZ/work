#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	TreeNode(int x)
		:val(x)
		,left(nullptr)
		,right(nullptr)
	{}
	int val;
	TreeNode* left;
	TreeNode* right;
};

//利用栈和中序遍历解决
TreeNode* KthNode(TreeNode* pRoot, int k)
{
	if (!pRoot || k == 0)
		return nullptr;
	int count = 0;
	stack<TreeNode*> s;
	TreeNode* cur = pRoot;
	while (!s.empty() || cur)
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		if (++count == k)
			return s.top();
		s.pop();
		cur = cur->right;
	}
	return nullptr;
}