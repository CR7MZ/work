//题目：https://www.nowcoder.com/questionTerminal/7fe2212963db4790b57431d9ed259701?answerType=1&f=discussion
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
//思路：
//此题归根到底就是用二叉树的层序遍历。
//用队列来遍历二叉树，先将头结点放入队列中，定义一个指针指向队列的头元素，将其值放入数组中。删除队列头元素。
//若cur的左右孩子都存在依次放入队列，继续进行上述操作。知道队列为空为止。
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