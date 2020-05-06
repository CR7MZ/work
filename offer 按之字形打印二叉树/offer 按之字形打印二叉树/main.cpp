#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x)
		:val(x)
		, left(nullptr)
		, right(nullptr)
	{}
};
//题目：https://www.nowcoder.com/questionTerminal/91b69814117f4e8097390d107d2efbe0?f=discussion
//思路：
//用两个栈是s1,s2。通过题意我们知道二叉树，奇数行按从左到右打印、偶数行按从右到左打印。

//因此s1来保存奇数行元素，入栈顺序为右-》左。
//而s2来保存偶数行元素，入栈顺序为左-》右。

//打印奇数行时从s1中取出元素，顺序为左到右打印。 
//打印偶数行时从s2中取出元素，顺序为右到左打印。 

class Solution {
public:
	vector<vector<int>> Print(TreeNode* pRoot) {
		vector<vector<int>> res;
		if (pRoot != nullptr)
		{
			stack<TreeNode*> s1, s2;
			s1.push(pRoot);
			while (!s1.empty() || !s2.empty())
			{
				vector<int> v1, v2;
				TreeNode* cur = nullptr;
				while (!s1.empty())
				{
					cur = s1.top();
					if (cur->left)
						s2.push(cur->left);
					if (cur->right)
						s2.push(cur->right);
					v1.push_back(s1.top()->val);
					s1.pop();
				}
				if (v1.size())
					res.push_back(v1);

				while (!s2.empty())
				{
					cur = s2.top();
					if (cur->right)
						s1.push(cur->right);
					if (cur->left)
						s1.push(cur->left);
					v2.push_back(s2.top()->val);
					s2.pop();
				}
				if (v2.size())
					res.push_back(v2);
			}
		}
		return res;
	}
};