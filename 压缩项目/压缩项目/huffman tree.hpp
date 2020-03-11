#pragma once
//���������Ĵ���
#include<queue>
#include<vector>
#include<iostream>

template<class T>
struct HuffManTreenode
{
	HuffManTreenode(const T& weight = T())
		:left(nullptr)
		, right(nullptr)
		, _parent(nullptr)
		, _weight(weight)
	{}
	HuffManTreenode<T>* left;
	HuffManTreenode<T>* right;
	HuffManTreenode<T>* _parent;
	T _weight;//�ڵ�Ȩֵ
};

template<class T>
class Less//�����ô��ڷ�ʽ���Ƚϣ�����С�ӵķ���
{
	typedef HuffManTreenode<T> node;
public:
	bool operator()(const node* left,const node* right)
	{
			return left->_weight > right->_weight;
	}
};

template<class T>
class Huffmantree
{
	typedef HuffManTreenode<T> node;
public:
	Huffmantree()
		:_root(nullptr)
	{}
	node* GetROOT()
	{
		return _root;
	}
	void CreatHuffmantree(const std::vector<T>& weight,const T& invalid)//����Huffman������Ȩֵ�ŵ�vector�д�����
		//invalid�����ṩ��Ч��Ȩֵ,����Ŀ�е���˼���ǽ�����Ϊ����ַ����Ž����
	{
		//1.����ɭ��
		std::priority_queue<node*,std::vector<node*>,Less<T>> q;//��Ϊ���ȼ�����Ĭ���������С�ڷ�ʽ���Ƚ����ɵ��Ǵ�ѣ�����������Ҫ����С�ѣ�������Ҫ�����ô��ڷ�ʽ���Ƚ�
		for (auto e : weight)
		{
			if (e == invalid)
				continue;

			q.push(new node(e));
		}

		//2.����Huffman��
		while (q.size() > 1)//��ɭ������һ�����ϵĽڵ�
		{
			node* left = q.top();//��ȡ����С�Ľڵ㣬��Ϊ��ڵ�
			q.pop();             //Ϊ��ȡ���ڶ�С�Ľڵ㣬ɾ����ʱ��С�Ľڵ�
			node* right = q.top();//��ȡ����ʱ��С�ڵ㣬��Ϊ�Һ��ӡ�
			q.pop();
			node* parent = new node(left->_weight + right->_weight);//parentΪ���ҽڵ�ĸ��ڵ㣬��ȨֵΪ���Һ��ӵ�Ȩֵ֮��
			parent->left = left;//���ҽڵ��Ϊparent�����Ӻ��к��ӣ��Դ���parentΪ�����µĶ�����������
			parent->right = right;
			left->_parent = parent;//����������_parentָ����ָ��parent�ڵ㡣
			right->_parent = parent;
			q.push(parent);//���µĶ������ٴβ��뵽ɭ���С�
		}
		_root = q.top();
	}
	~Huffmantree()
	{
		DestoryTree(_root);
	}
private:
	void DestoryTree(node*& root)//���������˴�Ҫע����������Ҫ�ı�ָ���ָ����Ҫ�ö���ָ�����ָ������ã������޷���������
	{
		if (root)//�ö������������˼�룬������
		{
			DestoryTree(root->left);
			DestoryTree(root->right);
			delete root;
			root = nullptr;
		}
	}
private:
	node* _root;
};