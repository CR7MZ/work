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

//迭代器
template <class T>
class RBIterator
{
public:
	typedef RBTreeNode<T> node;
	typedef RBIterator<T> self;
	RBIterator( node* node = nullptr) 
		:_ptr(node)
	{}

	T& operator*()
	{
		return _ptr->val;
	}

	T* operator->()
	{
		return &(operator*());
	}

	self& operator++()
	{
		Increase();
		return *this;
	}
	self operator++(int)
	{
		self tmp(*this);
		Increase();
		return tmp;
	}

	self& operator--()
	{
		Decrease();
		return *this;
	}
	self operator--(int)
	{
		self tmp(*this);//拷贝构造
		Decrease();
		return tmp;
	}

	bool operator==(const self& s)const 
	{
		return _ptr == s._ptr;
	}
	bool operator!=(const self& s)const 
	{
		return _ptr != s._ptr;
	}
private:
	//++操作,向后走找一个刚好比他的结点
	void Increase()
	{
		//找右子树中，最小的（最左边）的结点。
		if (_ptr->pRight)
		{
			_ptr = _ptr->pRight;
			while (_ptr->pLeft)
				_ptr = _ptr->pLeft;
		}
		else
		{
			node* pPParent = _ptr->pParent;
			while (pPParent->pRight == _ptr)
			{
				_ptr = pPParent;
				pPParent = _ptr->pParent;
			}

			//有一种特殊情况，根节点没有右子树，那么进行下面操作就会出问题。
			if (_ptr->pRight != pPParent)
			_ptr = pPParent;
		}
	}

	//--操作，向前走，找一个刚好比他小的结点。
	void Decrease()
	{
		//如果_ptr此时在end(),也就是_head，那么如果去左子树找就会出问题。
		//因此，需要把这种特殊情况解决：将_ptr指到其右指针域，也就是最大的结点。
		//区分_ptr是否在_head：不光要_ptr->pParent->pParent = _ptr，因为根节点也满足此条件，还要加上_ptr->clr == RED。
		if (_ptr->pParent->pParent = _ptr && _ptr->clr == RED)
		{
			_ptr = _ptr->pRight;
		}
		//找左子树中最大（最右）的结点
		else if (_ptr->pLeft)
		{
			_ptr = _ptr->pLeft;
			while (_ptr->pRight)
				_ptr = _ptr->pRight;
		}
		//没有左子树，在双亲中找
		else
		{
			node* pPParent = _ptr->pParent;
			while (pPParent->pLeft == _ptr)
			{
				_ptr = pParent;
				pPParent = _ptr->pParent;
			}

			//--没有++中的特殊情况，因为如果此时树的根节点没有左子树，那么_ptr在根的位置已经是树最小的结点，不能再--了。
				_ptr = pPParent;
		}
	}
private:
	node* _ptr;
};

//KOFV：
//因为map和set都有K，要用个方法从元素中提取key
template <class T,class KOFV>
class RBTree
{
public:
	typedef RBTreeNode<T> node; 
	typedef RBIterator<T> Iterator;
	RBTree()
	{
		_head = new RBTreeNode<T>;
		_head->pLeft = _head;
		_head->pRight = _head;
		_size = 0;
	}

	Iterator begin()
	{
		return Iterator(_head->pLeft);
	}

	Iterator end()
	{
		return Iterator(_head);
	}

	bool empty()const 
	{
		return _size == 0;
	}

	size_t size()const
	{
		return _size;
	}

	Iterator find(const T& val)
	{
		node* pCur = getRoot();
		while (pCur)
		{
			if (KOFV()(pCur->val) == KOFV()(val))
				return Iterator(pCur);
			else if (KOFV()(pCur->val) > KOFV()(val))
				pCur = pCur->pLeft;
			else
				pCur = pCur->pRight;
		}
		return end();
	}

	pair<Iterator,bool> insert(const T& data)
	{
		//插入新的节点
		node*& _root = getRoot();
		node* newNode = nullptr;
		if ( _root == nullptr)
		{
			_root = new node(data);
			_root->pParent = _head;
			_head->pParent = _root; 
			_size++;
			return make_pair(Iterator(_root), true);
		}
		else
		{
			//按二叉搜索树的方式插入结点
			node* pCur = _root;
			node* parent = nullptr;
			while (pCur)
			{
				parent = pCur;
				if (KOFV()(data) < KOFV()(pCur->val))
					pCur = pCur->pLeft;
				else if (KOFV()(data) > KOFV()(pCur->val))
					pCur = pCur->pRight;
				else
					return make_pair(Iterator(pCur), false);
			}
			
			newNode = new node(data);
			pCur = newNode;
			if (KOFV()(pCur->val) < KOFV()(parent->val))
				parent->pLeft = pCur;
			if (KOFV()(pCur->val) >  KOFV()(parent->val))
				parent->pRight = pCur;
			pCur->pParent = parent; 
			_size++;


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

		//因为在前面调调整颜色后，有可能将根节点变为红色。
		_root->clr = BLACK;
		_head->pLeft = MinNode(_root);
		_head->pRight = MaxNode(_root);
		return make_pair(Iterator(newNode), true);
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
	size_t _size;
};