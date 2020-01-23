//��Ŀ��https://leetcode-cn.com/problems/binary-tree-right-side-view/
#include<iostream>
#include<vector>
#include<queue>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
//���ò��������˼�룬һ��һ��ķ������ȶ�ÿ���ҽ����в������ٶ�ͬ�����ڵ���в������ҳ�ÿ�����ұߵĽ�㡣ֱ������Ϊ��
std::vector<int> rightSideView(TreeNode* root) {
	std::vector<int> res;
	if (root == nullptr)
		return res;
	std::queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int n = q.size();//ÿ��ڵ���
		res.push_back(q.front()->val);//��ÿ�����ұߵĽڵ������������
		while (n--)//ɾ��ÿ��Ľڵ㣬����ÿ���ڵ��Ӧ����һ��ڵ��������ŵ������С�
		{
			TreeNode* temp = q.front();
			q.pop();
			if (temp->right) q.push(temp->right);
			if (temp->left) q.push(temp->left);
		}
	}
	return res;
}