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

template<class T,class KOFV ,class DF = DFstr>//��Ϊ���Ƿ�װ�ĵ�����Ҫ�õ���ϣ���������ǹ�ϣ����ں��涨��ģ�
class Hash;                        //��������ڹ����������ʱ�򲢲�֪����ʱ��ϣ������ʲô���ӣ�������Ҫ��ǰ���������ܷ�װָ�롣����

template<class T, class KOFV,class DF = DFf()>//��Ϊ�õ���ϣ�࣬����ҲҪ�ѹ�ϣ����ģ�������������
struct HashIterator
{
	typedef HashNode<T> node;
	typedef HashIterator<T,KOFV,DF> self;
	HashIterator(node* pNode = nullptr, Hash<T,KOFV,DF>* ht = nullptr)
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
	Hash<T,KOFV,DF>* _ht;
};

template<class T,class KOFV,class DF >
class Hash
{
	friend struct HashIterator<T,KOFV,DF>;
	typedef HashNode<T> node;
public:
	typedef HashIterator<T,KOFV, DF> iterator;
	Hash(size_t cap = 10)
		:_size(0)
	{
		_table.resize(GetNextPrime(cap));
	}
	~Hash()
	{
		Clear();
	}
	//�����������ͬԪ�أ���ϣͰԪ��Ψһ
	std::pair<iterator,bool> insertunique(const T& data)
	{
		size_t Hashaddr = HashFunc(data);
		node* pcur = _table[Hashaddr];
		while (pcur)             //��Ͱ��������ͬ��㡣
		{
			if (KOFV()(pcur->_val) == KOFV()(data))
				return make_pair ( iterator(pcur, this), false ) ;
			pcur = pcur->_next;
		}

		//ͷ��
		pcur = new node(data);
		pcur->_next = _table[Hashaddr];
		_table[Hashaddr] = pcur;
		++_size;
		return make_pair(iterator(pcur, this), true);
	}
	size_t eraseunique(const T& data)
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

	void Clear()
	{
		for (size_t i = 0; i < _table.size(); i++)
		{
			node* cur = _table[i];
			while (cur)
			{
				_table[i] = cur->_next;
				delete cur;
				_size--;
				cur = _table[i];
			}
		}
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

	void Swap(Hash& ht)
	{
		_table.swap(ht._table);
		std::swap(_size, ht._size);
	}
	//Ͱ�ĸ���
	size_t bucket_count() const
	{
		return _table.capacity();
	}
	//ĳ��Ͱ�а����ڵ����
	size_t bucket_size(size_t bucketno) const
	{
		if (bucketno >= bucket_count())
			return 0;
		size_t count = 0;
		node* cur = _table[bucketno];
		while (cur)
		{
			count++;
			cur = cur->_next;
		}

		return count;
	}

	//��ȡ��ʱ��K���ĸ�Ͱ
	size_t bucket(const T& data)
	{
		return HashFunc(data);
	}
private:
	void check()
	{
		if (_size == _table.capacity())
		{
			//�½���һ���������Ĺ�ϣ��
			Hash<T,DF> NewHash(_table.capacity());

			//��ԭ��ϣͰ�н�㣬�����µĹ�ϣͰ��������Ҫ�ò���ӿڣ�Ч��̫�ͣ�ֱ�ӽ�֮ǰ�Ľ��ŵ��µĹ�ϣͰ�Ķ�Ӧ��ϣ��ַ�У�
			for (int HashBu = 0; HashBu < _table.capacity(); HashBu++)
			{
				node* cur = _table[HashBu];
				while (cur)
				{
					//�ȼ�����������¹�ϣ��ַ
					int Hashaddr = NewHash.HashFunc(cur->_val);

					//��cur�ӴӸ�Ͱ��ɾ��
					_table[HashBu] = cur->_next;

					//ͷ�����Ͱ
					cur->_next = NewHash._table[Hashaddr];
					NewHash._table[Hashaddr] = cur;

					//�Ż�ԭ����Ͱ�м�������
					cur = _table[HashBu];
				}
			}
			this->Swap(NewHash);
		}
	}
	size_t HashFunc(const T& data)const
	{
		return DF()(KOFV()(data)) % _table.capacity();
	}
private:
	std::vector<node*> _table;
	size_t _size;
};

//int main()
//{
//	Hash<int,DFf<int>> ht(10);
//	int arr[] = { 1, 5, 7, 6, 12, 23 };
//	for (auto e : arr)
//		ht.insertunique(e);
//	cout << ht.Size() << endl;
//	ht.print();
//
//	/*ht.eraseunique(5);
//	cout << ht.Size() << endl;
//	ht.print();*/
//
//	ht.insertunique(58);
//	ht.insertunique(22);
//	auto it = ht.begin();
//	while (it != ht.end())
//	{
//		cout << *it << " ";
//		it++; 
//	}
//	cout << endl;
//	ht.print();
//	//if (ht.find(25))
//	//	cout << " in " << endl;
//	//else
//	//	cout << " no " << endl;
//	ht.Clear();
//	system("pause");
//	return 0;
//}