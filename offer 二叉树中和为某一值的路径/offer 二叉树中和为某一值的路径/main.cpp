//��Ŀ��https://www.nowcoder.com/questionTerminal/b736e784e3e34731af99065031301bca?f=discussion
#include<iostream>
#include<vector>
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

//˼·��
//ͨ���ݹ����ÿһ���ڵ㣨�ȱ������ٱ����ң���ÿ����һ���ڵ㽫��ֵ����tmp�У�������ֵ��ȥĿǰ�ڵ��ֵ��������������һ������ֵ��
//���ҵ�Ҷ�ӽ�㲢�Ҵ�ʱ����ֵ���ڴ�ʱ����ֵ��˵��һ��·���Ѿ��ҵ�������·�����ظ�res���ɡ��������������������
//���ҵ�һ��·������ɾ��tmp�����һ�ڵ㣬�ټ���������·����
//��������Ҷ�ӽڵ㣬���Ǵ���·��������������ɾ��tmp���һ��Ԫ�ء���������·��

std::vector<std::vector<int>> res;//��ΪҪ��¼����·����������Ҫ����һ����ά��������������·����
                                 //����Ϊ��Ҫ�ݹ����ҵ�����·������˽�����Ϊȫ�ֱ�����

std::vector<int> tmp;//����ÿһ��·�������нڵ�ֵ��
void find(TreeNode* root, int expectNumber)
{
	if (root == nullptr)
		return;
	tmp.push_back(root->val);
	if (!root->left&&!root->right&&root->val == expectNumber)
		res.push_back(tmp);
	else
	{
		if (root->left)
			find(root->left, expectNumber - root->val);
		if (root->right)
			find(root->right, expectNumber - root->val);
	}
	tmp.pop_back();
}
std::vector<std::vector<int> > FindPath(TreeNode* root, int expectNumber) {
	find(root, expectNumber);
	return res;
}