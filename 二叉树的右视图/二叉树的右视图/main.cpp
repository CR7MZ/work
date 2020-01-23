//题目：https://leetcode-cn.com/problems/binary-tree-right-side-view/
#include<iostream>
#include<vector>
#include<queue>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
//利用层序遍历的思想，一层一层的分析，先对每层右结点进行操作，再对同层的左节点进行操作。找出每层最右边的结点。直到队列为空
std::vector<int> rightSideView(TreeNode* root) {
	std::vector<int> res;
	if (root == nullptr)
		return res;
	std::queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int n = q.size();//每层节点数
		res.push_back(q.front()->val);//将每层最右边的节点放入结果数组中
		while (n--)//删除每层的节点，并将每个节点对应的下一层节点从右向左放到队列中。
		{
			TreeNode* temp = q.front();
			q.pop();
			if (temp->right) q.push(temp->right);
			if (temp->left) q.push(temp->left);
		}
	}
	return res;
}