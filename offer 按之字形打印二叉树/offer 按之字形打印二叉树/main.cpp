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
//��Ŀ��https://www.nowcoder.com/questionTerminal/91b69814117f4e8097390d107d2efbe0?f=discussion
//˼·��
//������ջ��s1,s2��ͨ����������֪���������������а������Ҵ�ӡ��ż���а����ҵ����ӡ��

//���s1������������Ԫ�أ���ջ˳��Ϊ��-����
//��s2������ż����Ԫ�أ���ջ˳��Ϊ��-���ҡ�

//��ӡ������ʱ��s1��ȡ��Ԫ�أ�˳��Ϊ���Ҵ�ӡ�� 
//��ӡż����ʱ��s2��ȡ��Ԫ�أ�˳��Ϊ�ҵ����ӡ�� 

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