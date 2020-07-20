//��Ŀ��https://www.nowcoder.com/questionTerminal/564f4c26aa584921bc75623e48ca3011?f=discussion
#include<iostream>
//˼·��
//Ҫ��õ����ľ���ֻ���õݹ飬�Ե������������нڵ������ָ���򼴿ɡ�
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

//�ݹ�ⷨ
void Mirror(TreeNode *pRoot) {
	if (pRoot == nullptr)
		return;
	if (pRoot->left == nullptr&&pRoot->right == nullptr)
		return;
	TreeNode* tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

//ʹ��ջ���ǵݹ�
TreeNode* mirrorTree(TreeNode* root) {
          stack<TreeNode*> s;
          s.push(root);
          while(!s.empty()){
              TreeNode* tmp = s.top();
              s.pop();
              if (!tmp) continue;
              TreeNode* res = tmp->left;
              tmp->left = tmp->right;
              tmp->right = res;
              if (tmp->right != nullptr) s.push(tmp->right);
              if (tmp->left != nullptr) s.push(tmp->left);
          }
          return root;
    }