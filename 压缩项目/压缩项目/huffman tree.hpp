#pragma once
//哈夫曼树的创建
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
	T _weight;//节点权值
};

template<class T>
class Less//给出用大于方式来比较，生成小队的方法
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
	void CreatHuffmantree(const std::vector<T>& weight,const T& invalid)//创建Huffman树，将权值放到vector中传进来
		//invalid用来提供无效的权值,本项目中的意思就是将次数为零的字符不放进堆里。
	{
		//1.构建森林
		std::priority_queue<node*,std::vector<node*>,Less<T>> q;//因为优先级队列默认情况下用小于方式来比较生成的是大堆，但是我们需要的是小堆，所以需要给出用大于方式来比较
		for (auto e : weight)
		{
			if (e == invalid)
				continue;

			q.push(new node(e));
		}

		//2.构建Huffman树
		while (q.size() > 1)//当森林中有一个以上的节点
		{
			node* left = q.top();//先取出最小的节点，作为左节点
			q.pop();             //为了取出第二小的节点，删除此时最小的节点
			node* right = q.top();//再取出此时最小节点，作为右孩子。
			q.pop();
			node* parent = new node(left->_weight + right->_weight);//parent为左右节点的父节点，其权值为左右孩子的权值之和
			parent->left = left;//左右节点变为parent的左孩子和有孩子，以此以parent为根的新的二叉树建立。
			parent->right = right;
			left->_parent = parent;//左右子树的_parent指针域指向parent节点。
			right->_parent = parent;
			q.push(parent);//将新的二叉树再次插入到森林中。
		}
		_root = q.top();
	}
	~Huffmantree()
	{
		DestoryTree(_root);
	}
private:
	void DestoryTree(node*& root)//销毁树，此处要注意若函数内要改变指针的指向，需要用二级指针或者指针的引用，否则无法带出函数
	{
		if (root)//用二叉树后序遍历思想，来销毁
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