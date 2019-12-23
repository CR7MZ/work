//��Ŀ��https://www.nowcoder.com/questionTerminal/7fe2212963db4790b57431d9ed259701?answerType=1&f=discussion
#include<iostream>
#include<queue>
#include<vector>
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x)
		:val(x)
		,left(nullptr)
		,right(nullptr)
	{}
};
//˼·��
//���������׾����ö������Ĳ��������
//�ö������������������Ƚ�ͷ����������У�����һ��ָ��ָ����е�ͷԪ�أ�����ֵ���������С�ɾ������ͷԪ�ء�
//��cur�����Һ��Ӷ��������η�����У�������������������֪������Ϊ��Ϊֹ��
std::vector<int> PrintFromTopToBottom(TreeNode* root)
{
	std::vector<int> v;
	std::queue<TreeNode*> q;
	if (root == nullptr)
		return v;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* cur = q.front();
		v.push_back(cur->val);
		q.pop();
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);
	}
	return v;
}