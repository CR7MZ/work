#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
enum color {RED , BLACK};

template <class T>
struct RBTreeNode
{
	RBTreeNode(const T& x = T())
		: val(x)
		, clr(RED)
		, pLeft(nullptr)
		, pRight(nullptr)
		, pParent(nullptr)
	{}
	T val;
	color clr;
	struct RBTreeNode<T>* pLeft;
	struct RBTreeNode<T>* pRight;
	struct RBTreeNode<T>* pParent;
};

template <class T>
class RBTree
{
public:
	typedef RBTreeNode<T> node; 
	RBTree()
	{
		_head = new RBTreeNode<T>;
		_head->pLeft = _head;
		_head->pRight = _head;
	}
	bool insert(const T& data)
	{
		//插入新的节点
		node*& _root = getRoot();
		if ( _root == nullptr)
		{
			_root = new RBTreeNode<T>(data);
			_root->pParent = _head;
			_head->pParent = _root;
		}
		else
		{
			//按二叉搜索树的方式插入结点
			node* pCur = _root;
			node* parent = nullptr;
			while (pCur)
			{
				parent = pCur;
				if (data < pCur->val)
					pCur = pCur->pLeft;
				else if(data > pCur->val)
					pCur = pCur->pRight;
				else
					return false;
			}
			pCur = new RBTreeNode<T>(data);
			if (pCur->val < parent->val)
				parent->pLeft = pCur;
			if (pCur->val > parent->val)
				parent->pRight = pCur;
			pCur->pParent = parent;


			//检测相信插入节点后，红黑树的性质是否被破坏。若满足直接退出，否则对此事的红黑树进行处理。
			while (parent != _head &&parent->clr == RED)//如果parent为_head，则不用向上继续更改了。
			{
				node* GraFa = parent->pParent;
				//左半边树
				if (parent == GraFa->pLeft)
				{
					node* uncle = GraFa->pRight;
					if (uncle && uncle->clr == RED)//第一种情况
					{
						//调整颜色，满足性质
						parent->clr = BLACK;
						uncle->clr = BLACK;
						GraFa->clr = RED;

						pCur = GraFa;
						parent = pCur->pParent;
					}
					else//第二三种情况
					{
						if (pCur == parent->pRight)//先处理第三种情况，将其变为第二种情况的格式，最后一同处理。
						{
							RolateL(parent);
							swap(parent, pCur);
						}
							
						parent->clr = BLACK;
						GraFa->clr = RED;
						RolateR(GraFa);
					}
				}

				//右半边树
				else
				{
					node* uncle = GraFa->pLeft;
					if (uncle && uncle->clr == RED)//第一种情况
					{
						//调整颜色，满足性质
						parent->clr = BLACK;
						uncle->clr = BLACK;
						GraFa->clr = RED;

						pCur = GraFa;
						parent = pCur->pParent;
					}
					else//第二三种情况
					{
						if (pCur == parent->pLeft)//先处理第三种情况，将其变为第二种情况的格式，最后一同处理。
						{
							RolateR(parent);
							swap(pCur, parent);
						}

						parent->clr = BLACK;
						GraFa->clr = RED;
						RolateL(GraFa);
					}
				}
			}
		}

		_root->clr = BLACK;
		_head->pLeft = MinNode(_root);
		_head->pRight = MaxNode(_root);
		return true;
	}

	//检测是否是有效的红黑树
	bool IsVaildRBTree()
	{
		//根节点为空，为红黑树
		if (_head->pParent == nullptr)
			return true;

		if (BLACK != _head->pParent->clr)
		{
			cout << "根节点颜色是红色，违反性质2" << endl;
			return false;
		}

		//检验是否满足第三以及第四个性质
		//统计一条路径中黑色结点的个数。
		size_t BlackNode = 0;
		node* pCur = _head->pParent;
		while (pCur)
		{
			if (pCur->clr == BLACK)
				BlackNode++;
			pCur = pCur->pLeft;
		}

		//统计每条路径黑色节点的个数，与BlackNode相比较，相同则说明是，否则不是。
		size_t path = 0;
		return IsVaild(_head->pParent, path, BlackNode);
	}
private:
	//path统计每条路径中，黑色节点的个数
	bool IsVaild(node* root, size_t path, size_t BlackNode)
	{
		if (root == nullptr)
			return true;

		if (BLACK == root->clr)
			path++;

		//验证相性质三是否满足
		node* pPParent = root->pParent;
		if (pPParent->pParent != _head&&RED == pPParent->clr&&RED == root->clr)
		{
			cout << "有相连的两个红结点：违反性质3" << endl;
			return false;
		}

		if (root->pLeft == nullptr&&root->pRight == nullptr)
		{
			if (path != BlackNode)
			{
				cout << "每条路径中黑色节点数目不一致：出错！！！" << endl;
				return false;
			}
		}

		return IsVaild(root->pLeft, path, BlackNode) &&
			IsVaild(root->pRight, path, BlackNode);
	}
	node*& getRoot()
	{
		return _head->pParent;
	}
	node* MinNode(node* _root)
	{
		if (_root == nullptr)
			return nullptr;

		node* cur = _root;
		while (cur->pLeft)
		{
			cur = cur->pLeft;
		}
		return cur;
	}

	node* MaxNode(node* _root)
	{
		if (_root == nullptr)
			return nullptr;

		node* cur = _root;
		while (cur->pRight)
		{
			cur = cur->pRight;
		}
		return cur;
	}

	void RolateL(node* root) //左单旋
	{
		node* R = root->pRight;
		node* RL = R->pLeft;

		root->pRight = RL;
		if (RL)
			RL->pParent = root;
		R->pLeft = root;

		node* pPParent = root->pParent;
		root->pParent = R;
		R->pParent = pPParent;
		if (pPParent == _head)//说明此时_root 为根节点，pPParent为_head，此时是将_head的父指针域指向旋转后的R。
		{
			_head->pParent = R;
		}
		else
		{
			if (pPParent->pLeft == root)
				pPParent->pLeft = R;
			else
				pPParent->pRight = R;
		}	
	}
	void RolateR(node* root) //右单旋
	{
		node* L = root->pLeft;
		node* LR = L->pRight;

		root->pLeft = LR;
		if (LR)
			LR->pParent = root;
		L->pRight = root;

		node* pPParent = root->pParent;
		root->pParent = L;
		L->pParent = pPParent;

		if (pPParent == _head)//说明此时_root 为根节点，pPParent为_head，此时是将_head的父指针域指向旋转后的R。
		{
			_head->pParent = L;
		}
		if (pPParent->pLeft == root)
			pPParent->pLeft = L;
		if (pPParent->pRight == root)
			pPParent->pRight = L;
	}
private:
	node* _head;
};