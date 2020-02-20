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

template<class T,class DF=DFf<T>>
class Hash
{
	typedef HashNode<T> node;
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

	ht.insertunique(25);
	ht.insertunique(22);
	cout << ht.Size() << endl;
	ht.print();

	if (ht.find(25))
		cout << " in " << endl;
	else
		cout << " no " << endl;
	system("pause");
	return 0;
}