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
			return _ht.eraseunique(key);//默认V的值用V()表示
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

	// 构造键值对的两种方式：pair结构体  make_pair
	m.insert("apple");
	m.insert("banana");
	m.insert("orange");
	m.insert("peach");

	cout << m.Size() << endl;
	cout << m.bucket_count() << endl;  // 桶的个数
	cout << m.bucket_size(0) << endl;  // 0号桶中的元素个数
	cout << m.bucket("orange") << endl;   // 获取key所在的桶号

	// key不能重复
	m.insert("apple");
	cout << m.Size() << endl;

	m.erase("orange");
	cout << m.Size() << endl;

	m.clear();
}