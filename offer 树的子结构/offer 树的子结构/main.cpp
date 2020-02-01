//��Ŀ��https://www.nowcoder.com/questionTerminal/6e196c44c7004d15b1610b9afca8bd88?f=discussion
#include<iostream>
//pRoot1ΪA,pRoot2ΪB��
//˼·��
//��ɴ����Ϊ������
//1.����A�����ҵ���B�ĸ��ڵ��ֵһ���Ľڵ�R��
//2.���ж�A������RΪ���ڵ�������Ƿ��������Bһ���Ľṹ��
//��һ����
//����A������B���ڵ�ֵ��ͬ�Ľڵ�R��Ҳ���������ı������ݹ����HasSubtree������
//������һ�����B���ڵ��ֵ��ͬ������IsSubtree������������һ��

//�ڶ�����
//�ݹ����IsSubtree���ж�B���Ƿ�����RΪ���ڵ������������ͬ�Ľṹ��
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
bool IsSubtree(TreeNode* R, TreeNode* pRoot2)
{
	if (R == nullptr&&pRoot2 != nullptr)//���RΪ�գ���B��Ϊ�գ�˵����ƥ�䡣
		return false;
	if (pRoot2 == nullptr)//����ֻҪBΪ�գ�˵��ƥ��
		return true;
	if (R->val != pRoot2->val)//����ֵ����ȣ���ƥ��
		return false;
	return IsSubtree(R->left, pRoot2->left) && IsSubtree(R->right, pRoot2->right);//�ݹ��ж�����������
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool res = false;
	if (pRoot1 != nullptr&&pRoot2 != nullptr)
	{
		if (pRoot1->val == pRoot2->val)
			res = IsSubtree(pRoot1, pRoot2);
		if (!res)
			res = HasSubtree(pRoot1->left, pRoot2);
		if (!res)
			res = HasSubtree(pRoot1->right, pRoot2);
	}
	return res;
}
