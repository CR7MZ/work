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

//������
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
		self tmp(*this);//��������
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
	//++����,�������һ���պñ����Ľ��
	void Increase()
	{
		//���������У���С�ģ�����ߣ��Ľ�㡣
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

			//��һ��������������ڵ�û������������ô������������ͻ�����⡣
			if (_ptr->pRight != pPParent)
			_ptr = pPParent;
		}
	}

	//--��������ǰ�ߣ���һ���պñ���С�Ľ�㡣
	void Decrease()
	{
		//���_ptr��ʱ��end(),Ҳ����_head����ô���ȥ�������Ҿͻ�����⡣
		//��ˣ���Ҫ��������������������_ptrָ������ָ����Ҳ�������Ľ�㡣
		//����_ptr�Ƿ���_head������Ҫ_ptr->pParent->pParent = _ptr����Ϊ���ڵ�Ҳ�������������Ҫ����_ptr->clr == RED��
		if (_ptr->pParent->pParent = _ptr && _ptr->clr == RED)
		{
			_ptr = _ptr->pRight;
		}
		//����������������ң��Ľ��
		else if (_ptr->pLeft)
		{
			_ptr = _ptr->pLeft;
			while (_ptr->pRight)
				_ptr = _ptr->pRight;
		}
		//û������������˫������
		else
		{
			node* pPParent = _ptr->pParent;
			while (pPParent->pLeft == _ptr)
			{
				_ptr = pParent;
				pPParent = _ptr->pParent;
			}

			//--û��++�е������������Ϊ�����ʱ���ĸ��ڵ�û������������ô_ptr�ڸ���λ���Ѿ�������С�Ľ�㣬������--�ˡ�
				_ptr = pPParent;
		}
	}
private:
	node* _ptr;
};

//KOFV��
//��Ϊmap��set����K��Ҫ�ø�������Ԫ������ȡkey
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
		//�����µĽڵ�
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
			//�������������ķ�ʽ������
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


			//������Ų���ڵ�󣬺�����������Ƿ��ƻ���������ֱ���˳�������Դ��µĺ�������д���
			while (parent != _head &&parent->clr == RED)//���parentΪ_head���������ϼ��������ˡ�
			{
				node* GraFa = parent->pParent;
				//������
				if (parent == GraFa->pLeft)
				{
					node* uncle = GraFa->pRight;
					if (uncle && uncle->clr == RED)//��һ�����
					{
						//������ɫ����������
						parent->clr = BLACK;
						uncle->clr = BLACK;
						GraFa->clr = RED;

						pCur = GraFa;
						parent = pCur->pParent;
					}
					else//�ڶ��������
					{
						if (pCur == parent->pRight)//�ȴ������������������Ϊ�ڶ�������ĸ�ʽ�����һͬ����
						{
							RolateL(parent);
							swap(parent, pCur);
						}
							
						parent->clr = BLACK;
						GraFa->clr = RED;
						RolateR(GraFa);
					}
				}

				//�Ұ����
				else
				{
					node* uncle = GraFa->pLeft;
					if (uncle && uncle->clr == RED)//��һ�����
					{
						//������ɫ����������
						parent->clr = BLACK;
						uncle->clr = BLACK;
						GraFa->clr = RED;

						pCur = GraFa;
						parent = pCur->pParent;
					}
					else//�ڶ��������
					{
						if (pCur == parent->pLeft)//�ȴ������������������Ϊ�ڶ�������ĸ�ʽ�����һͬ����
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

		//��Ϊ��ǰ���������ɫ���п��ܽ����ڵ��Ϊ��ɫ��
		_root->clr = BLACK;
		_head->pLeft = MinNode(_root);
		_head->pRight = MaxNode(_root);
		return make_pair(Iterator(newNode), true);
	}

	//����Ƿ�����Ч�ĺ����
	bool IsVaildRBTree()
	{
		//���ڵ�Ϊ�գ�Ϊ�����
		if (_head->pParent == nullptr)
			return true;

		if (BLACK != _head->pParent->clr)
		{
			cout << "���ڵ���ɫ�Ǻ�ɫ��Υ������2" << endl;
			return false;
		}

		//�����Ƿ���������Լ����ĸ�����
		//ͳ��һ��·���к�ɫ���ĸ�����
		size_t BlackNode = 0;
		node* pCur = _head->pParent;
		while (pCur)
		{
			if (pCur->clr == BLACK)
				BlackNode++;
			pCur = pCur->pLeft;
		}

		//ͳ��ÿ��·����ɫ�ڵ�ĸ�������BlackNode��Ƚϣ���ͬ��˵���ǣ������ǡ�
		size_t path = 0;
		return IsVaild(_head->pParent, path, BlackNode);
	}
private:
	//pathͳ��ÿ��·���У���ɫ�ڵ�ĸ���
	bool IsVaild(node* root, size_t path, size_t BlackNode)
	{
		if (root == nullptr)
			return true;

		if (BLACK == root->clr)
			path++;

		//��֤���������Ƿ�����
		node* pPParent = root->pParent;
		if (pPParent->pParent != _head&&RED == pPParent->clr&&RED == root->clr)
		{
			cout << "���������������㣺Υ������3" << endl;
			return false;
		}

		if (root->pLeft == nullptr&&root->pRight == nullptr)
		{
			if (path != BlackNode)
			{
				cout << "ÿ��·���к�ɫ�ڵ���Ŀ��һ�£���������" << endl;
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

	void RolateL(node* root) //����
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
		if (pPParent == _head)//˵����ʱ_root Ϊ���ڵ㣬pPParentΪ_head����ʱ�ǽ�_head�ĸ�ָ����ָ����ת���R��
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
	void RolateR(node* root) //�ҵ���
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

		if (pPParent == _head)//˵����ʱ_root Ϊ���ڵ㣬pPParentΪ_head����ʱ�ǽ�_head�ĸ�ָ����ָ����ת���R��
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