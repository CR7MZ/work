#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
//��Ŀ��https://www.nowcoder.com/questionTerminal/445c44d982d04483b04a54f298796288?f=discussion
//����������q1,q2��q1����������е���ֵ��q2����ż�������ݡ�ÿ��ÿ�����д�ӡ�Լ�������ʱ������һ�е����ݱ�������һ�������С��������ơ�
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> res;
		if (pRoot != nullptr)
		{
			TreeNode* cur = nullptr;
			queue<TreeNode*> q1, q2;
			q1.push(pRoot);
			while (!q1.empty() || !q2.empty())
			{
				vector<int> ret1, ret2;
				while (!q1.empty())
				{
					cur = q1.front();
					if (cur->left)
						q2.push(cur->left);
					if (cur->right)
						q2.push(cur->right);

					ret1.push_back(cur->val);
					q1.pop();
				}
				if (ret1.size())
					res.push_back(ret1);

				while (!q2.empty())
				{
					cur = q2.front();
					if (cur->left)
						q1.push(cur->left);
					if (cur->right)
						q1.push(cur->right);

					ret2.push_back(cur->val);
					q2.pop();
				}
				if (ret2.size())
					res.push_back(ret2);
			}
		}
		return res;
	}
};