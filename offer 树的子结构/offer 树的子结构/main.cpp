//题目：https://www.nowcoder.com/questionTerminal/6e196c44c7004d15b1610b9afca8bd88?f=discussion
#include<iostream>
//pRoot1为A,pRoot2为B。
//思路：
//完成此题分为两步：
//1.先在A树中找到和B的根节点的值一样的节点R。
//2.在判断A树中以R为根节点的子树是否包含和树B一样的结构。
//第一步：
//在树A中找与B根节点值相同的节点R。也就是用树的遍历。递归调用HasSubtree函数。
//若发现一结点与B根节点的值相同，调用IsSubtree函数，进行下一步

//第二步：
//递归调用IsSubtree，判断B树是否与以R为根节点的子树具有相同的结构。
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
	if (R == nullptr&&pRoot2 != nullptr)//如果R为空，且B不为空，说明不匹配。
		return false;
	if (pRoot2 == nullptr)//或者只要B为空，说明匹配
		return true;
	if (R->val != pRoot2->val)//两者值不相等，不匹配
		return false;
	return IsSubtree(R->left, pRoot2->left) && IsSubtree(R->right, pRoot2->right);//递归判断左右子树。
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
