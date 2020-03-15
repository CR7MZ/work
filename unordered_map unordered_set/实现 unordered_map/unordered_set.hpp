#pragma once 
#include "Hash.hpp"
#include <string>

namespace My
{
	template<class K>
	class unordered_set
	{
	public:
		struct KOFV
		{
			const K& operator()(const K& data)const
			{
				return data;
			}
		};

		typename typedef Hash<K, KOFV>::iterator iterator;
	public:
		unordered_set()
			:_ht()
		{}
		size_t Size()
		{
			return _ht.Size();
		}

		bool empty()const
		{
			return _ht.Size() == 0;
		}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		std::pair<iterator, bool> insert(const K& data)
		{
			return _ht.insertunique(data);
		}

		size_t erase(const K& key)
		{
			return _ht.eraseunique(key);//Ĭ��V��ֵ��V()��ʾ
		}

		iterator find(const K& key)
		{
			return _ht.find(key);
		}

		void clear()
		{
			_ht.Clear();
		}

		void swap(const unordered_set<K>& m)
		{
			_ht.Swap(m._ht);
		}
		size_t bucket_count()
		{
			return _ht.bucket_count();
		}

		size_t bucket_size(size_t n)const
		{
			return _ht.bucket_size(n);
		}

		size_t bucket(const K& key)
		{
			return _ht.bucket(key);
		}
	private:
		Hash<K, KOFV> _ht;
	};
}

void TestUnorderedSet()
{
	My::unordered_set<string> m;

	// �����ֵ�Ե����ַ�ʽ��pair�ṹ��  make_pair
	m.insert("apple");
	m.insert("banana");
	m.insert("orange");
	m.insert("peach");

	cout << m.Size() << endl;
	cout << m.bucket_count() << endl;  // Ͱ�ĸ���
	cout << m.bucket_size(0) << endl;  // 0��Ͱ�е�Ԫ�ظ���
	cout << m.bucket("orange") << endl;   // ��ȡkey���ڵ�Ͱ��

	// key�����ظ�
	m.insert("apple");
	cout << m.Size() << endl;

	m.erase("orange");
	cout << m.Size() << endl;

	m.clear();
}