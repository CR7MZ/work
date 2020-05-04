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

//��Ŀ��https://www.nowcoder.com/questionTerminal/ff05d44dfdb04e1d83bdbdab320efbcb?f=discussion
//�Ӹ��ڵ㿪ʼ�ж���������������������������Ӧ��������������������ͬ
//��������������������������������ͬ

//�ݹ�ʵ��
class Solution1 {
public:
	bool Func(TreeNode* left, TreeNode* right)//�ж����������Ƿ���ͬ
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

//�ǵݹ�ʵ�֡�ʹ��ջ
//����һ��ջ��������ɶԵĽ�㣬ÿ��ȡ��һ�Խ��
//1.�����Ϊ�գ�����
//2.�������һ��Ϊ�գ���һ����Ϊ�շ���false;
//3.����Ϊ�գ��Ƚϵ�ǰֵ����ͬ����false;
//��ջ˳���ǳɶԵģ��磺left->left��rright->right��
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