#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

//题目：https://www.nowcoder.com/questionTerminal/ff05d44dfdb04e1d83bdbdab320efbcb?f=discussion
//从根节点开始判断其左右子树，左子树的左子树应该与右子树的右子树相同
//左子树的右子树与右子树的左子树相同

//递归实现
class Solution1 {
public:
	bool Func(TreeNode* left, TreeNode* right)//判断左右子树是否相同
	{
		if (left == nullptr) return right == nullptr;
		if (right == nullptr) return false;
		if (left->val != right->val)
			return false;
		return Func(left->left, right->right) && Func(left->right, right->left);
	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;
		return Func(pRoot->left, pRoot->right);
	}

};

//非递归实现。使用栈
//定义一个栈，来保存成对的结点，每次取出一对结点
//1.如果都为空，继续
//2.如果其中一个为空，另一个不为空返回false;
//3.都不为空，比较当前值，不同返回false;
//入栈顺序都是成对的，如：left->left和rright->right等
class Solution2 {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;
		stack<TreeNode*> s;
		s.push(pRoot->left);
		s.push(pRoot->right);
		while (!s.empty())
		{
			TreeNode* right = s.top();
			s.pop(); 
			TreeNode* left = s.top();
			s.pop();
			if (left == nullptr&& right == nullptr)
				continue;
			if (left == nullptr || right == nullptr)
				return false;
			if (left->val != right->val)
				return false;
			s.push(left->left);
			s.push(right->right);
			s.push(left->right);
			s.push(right->left);
		}
		return true;
	}

};