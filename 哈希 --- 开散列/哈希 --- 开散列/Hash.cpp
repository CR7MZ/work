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

template<class T, class DF = DFf<T>>//��Ϊ���Ƿ�װ�ĵ�����Ҫ�õ���ϣ���������ǹ�ϣ����ں��涨��ģ�
class Hash;                        //��������ڹ����������ʱ�򲢲�֪����ʱ��ϣ������ʲô���ӣ�������Ҫ��ǰ���������ܷ�װָ�롣����

template<class T,class DF = DFf()>//��Ϊ�õ���ϣ�࣬����ҲҪ�ѹ�ϣ����ģ�������������
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

	self& operator++()//�˴���Ϊ���Ǵ������������next�����н���Ѿ��ƶ��ˣ����Է���ֵ����ʹ����Ҳ���Բ���
	{                 //����������һ�������Ŀռ䣬�ͱ��뷵�����ã���Ϊ��������������ã����൱�����ǵ�ָ�벢û�ж���
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
		if (_pNode->_next)//�����ֵ������һ�����
			_pNode = _pNode->_next;
		else                    //����һ����ֵ��Ͱ
		{
			size_t Nextno = _ht->HashFunc(_pNode->_val) + 1;//�����һ��Ͱ��
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
	//�����������ͬԪ�أ���ϣͰԪ��Ψһ
	bool insertunique(const T& data)
	{
		size_t Hashaddr = HashFunc(data);
		node* pcur = _table[Hashaddr];
		while (pcur)             //��Ͱ��������ͬ��㡣
		{
			if (pcur->_val == data)
				return false;
			pcur = pcur->_next;
		}

		//ͷ��
		pcur = new node(data);
		pcur->_next = _table[Hashaddr];
		_table[Hashaddr] = pcur;
		++_size;
		return true;
	}
	bool eraseunique(const T& data)
	{
		size_t Hashaddr = HashFunc(data);//�õ���ϣ��ַ

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
		for (size_t i = 0; i < _table.capacity(); i++)//�ҵ�һ���ǿ�Ͱ
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