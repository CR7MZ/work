//题目：https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5?f=discussion
//详细解析：https://blog.csdn.net/CR7lmz/article/details/104198092
#include<iostream>
#include<vector>
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x)
		,left(nullptr)
		,right(nullptr)
	{}
};
//思路1：
class solution1
{
	TreeNode* head = nullptr;
	TreeNode* realhead = nullptr;
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
			return nullptr;
		Convert(pRootOfTree->left);
		if (head == nullptr)
		{
			head = pRootOfTree;
			realhead = pRootOfTree;
		}
		else{
			head->right = pRootOfTree;
			pRootOfTree->left = head;
			head = pRootOfTree;
		}
		Convert(pRootOfTree->right);
		return realhead;
	}
};

//思路2：
class Solution2 {
	std::vector<TreeNode*> v;
public:
	void Func(TreeNode* root)//中序遍历
	{
		if (root->left)
			Func(root->left);
		v.push_back(root);
		if (root->right)
			Func(root->right);
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if ((pRootOfTree == nullptr) || (!pRootOfTree->left) && (!pRootOfTree->right))
			return pRootOfTree;
		Func(pRootOfTree);
		v[0]->left = nullptr;
		v[0]->right = v[1];
		size_t i = 1;
		for (; i<v.size() - 1; i++)
		{
			v[i]->left = v[i - 1];
			v[i]->right = v[i + 1];
		}
		v[i]->left = v[i - 1];
		v[i]->right = nullptr;
		return v[0];
	}
};