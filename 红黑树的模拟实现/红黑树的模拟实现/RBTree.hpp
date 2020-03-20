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
		//�����µĽڵ�
		node*& _root = getRoot();
		if ( _root == nullptr)
		{
			_root = new RBTreeNode<T>(data);
			_root->pParent = _head;
			_head->pParent = _root;
		}
		else
		{
			//�������������ķ�ʽ������
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

		_root->clr = BLACK;
		_head->pLeft = MinNode(_root);
		_head->pRight = MaxNode(_root);
		return true;
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
};