#include <iostream>
#include <string>
#include <stack>
using namespace std;
string str;
int i;
struct TreeNode
{
	char val;
	struct TreeNode *left, *right;
	TreeNode(char c) :val(c), left(NULL), right(NULL) {}
};

TreeNode* CreateBinTree()
{
	char c = str[i++];
	if (c == '#')
		return NULL;
	TreeNode* root = new TreeNode(c);
	root->left = CreateBinTree();
	root->right = CreateBinTree();
	return root;
}
void Inor(TreeNode* root)//ÖÐÐò±éÀú
{
	if (root==nullptr)return;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	while (!s.empty()||cur!=nullptr)
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		cout << cur->val << " ";
		s.pop();
		cur = cur->right;
	}
}
int main()
{
	while (cin >> str)
	{
		i = 0;
		TreeNode* root = CreateBinTree();
		Inor(root);
		cout << endl;
	}
	return 0;
}