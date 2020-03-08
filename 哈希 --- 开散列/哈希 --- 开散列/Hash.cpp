#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Common.h"
using namespace std;

template<class T>
struct HashNode
{
	HashNode(const T& val=T())
		:_val(val)
		,_next(nullptr)
	{}
	T _val;
	HashNode<T>* _next;
};

template<class T, class DF = DFf<T>>//因为我们封装的迭代器要用到哈希函数，但是哈希类的在后面定义的，
class Hash;                        //因此我们在构造迭代器的时候并不知道此时哈希类型是什么样子，所以需要提前声明，才能封装指针。、、

template<class T,class DF = DFf()>//因为用到哈希类，所以也要把哈希函数模板参数传过来。
struct HashIterator
{
	typedef HashNode<T> node;
	typedef HashIterator<T,DF> self;
	HashIterator(node* pNode = nullptr, Hash<T,DF>* ht = nullptr)
		:_pNode(pNode)
		, _ht(ht)
	{}

	T& operator* ()
	{
		return _pNode->_val;
	}

	T* operator->()
	{
		return &(_pNode->_val);
	}

	self& operator++()//此处因为我们处理的是链表，在next函数中结点已经移动了，所以返回值可以使引用也可以不是
	{                 //但是若处理一段连续的空间，就必须返回引用，因为，如果不反悔引用，就相当于我们的指针并没有动。
  		Next();
		return *this;
	}

	self operator++(int)
	{
		self tmp(*this);
		Next();
		return tmp;
	}

	bool operator!=(const self &s)
	{
		return _pNode != s._pNode;
	}

	bool operator==(const self &s)
	{
		return _pNode == s._pNode;
	}

	void Next()
	{
		if (_pNode->_next)//如果有值，到下一个结点
			_pNode = _pNode->_next;
		else                    //找下一个有值的桶
		{
			size_t Nextno = _ht->HashFunc(_pNode->_val) + 1;//获得下一个桶号
			for (; Nextno < _ht->_table.size(); Nextno++)
			{
				if (_ht->_table[Nextno])
				{
					_pNode = _ht->_table[Nextno];
					return;
				}
			}
			_pNode = nullptr;
		}
	}
	node* _pNode;
	Hash<T,DF>* _ht;
};

template<class T,class DF>
class Hash
{
	friend struct HashIterator<T,DF>;
	typedef HashNode<T> node;
	typedef HashIterator<T, DF> iterator;
public:
	Hash(size_t cap)
		:_size(0)
	{
		_table.resize(GetNextPrime(cap));
	}
	~Hash()
	{
		_size = 0;
	}
	//不允许插入相同元素，哈希桶元素唯一
	bool insertunique(const T& data)
	{
		size_t Hashaddr = HashFunc(data);
		node* pcur = _table[Hashaddr];
		while (pcur)             //看桶中有无相同结点。
		{
			if (pcur->_val == data)
				return false;
			pcur = pcur->_next;
		}

		//头插
		pcur = new node(data);
		pcur->_next = _table[Hashaddr];
		_table[Hashaddr] = pcur;
		++_size;
		return true;
	}
	bool eraseunique(const T& data)
	{
		size_t Hashaddr = HashFunc(data);//得到哈希地址

		node* pcur = _table[Hashaddr];
		node* pre = nullptr;
		while (pcur)
		{
			if (pcur->_val == data)
			{
				if (pre == nullptr)
				{
					_table[Hashaddr] = pcur->_next;
				}
				else
				{
					pre->_next = pcur->_next;
				}
				delete pcur;
				pcur = nullptr;
				--_size;
				return true;
			}
			pre = pcur;
			pcur = pcur->_next;
		}
		return false;
	}

	node* find(const T& data)
	{
		size_t Hashaddr = HashFunc(data);
		node* pcur = _table[Hashaddr];
		while (pcur)
		{
			if (pcur->_val == data)
				return pcur;
			pcur = pcur->_next;
		}
		return nullptr;
	}

	size_t Size()
	{
		return _size;
	}

	void print()
	{
		for (size_t i = 0; i < _table.size(); i++)
		{
			node* pcur = _table[i];
			cout << "_table [" << i << "]:";
			while (pcur)
			{
				cout << pcur->_val << "---->";
				pcur = pcur->_next;
			}
			cout << "nullptr" << endl;
		}
	}

	iterator begin()
	{
		for (size_t i = 0; i < _table.capacity(); i++)//找第一个非空桶
		{
			if (_table[i])
				return iterator(_table[i],this);
		}
		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}
private:
	void check()
	{

	}
	size_t HashFunc(const T& data)const
	{
		return DF()(data) % _table.capacity();
	}
private:
	std::vector<node*> _table;
	size_t _size;
};

int main()
{
	Hash<int> ht(10);
	int arr[] = { 1, 5, 7, 6, 12, 23 };
	for (auto e : arr)
		ht.insertunique(e);
	cout << ht.Size() << endl;
	ht.print();

	/*ht.eraseunique(5);
	cout << ht.Size() << endl;
	ht.print();*/

	ht.insertunique(58);
	ht.insertunique(22);
	auto it = ht.begin();
	while (it != ht.end())
	{
		cout << *it << " ";
		it++; 
	}
	cout << endl;
	ht.print();
	//if (ht.find(25))
	//	cout << " in " << endl;
	//else
	//	cout << " no " << endl;
	system("pause");
	return 0;
}