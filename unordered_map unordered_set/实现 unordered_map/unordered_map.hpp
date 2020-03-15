#pragma once 
#include "Hash.hpp"
#include <string>

namespace My
{
	template<class K,class V>
	class unordered_map
	{
	public:
		typedef std::pair<K, V> ValueType;
	public:	
		struct KOFV
		{
			const K& operator()(const ValueType& data)const
			{
				return data.first;
			}
		};

		typename typedef Hash<ValueType, KOFV>::iterator iterator;
	public:
		unordered_map()
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

		std::pair<iterator, bool> insert(const ValueType& data)
		{
			return _ht.insertunique(data);
		}

		size_t erase(const K& key)
		{
			return _ht.eraseunique(ValueType(key, V()));//默认V的值用V()表示
		}

		iterator find(const K& key)
		{
			return _ht.find(ValueType(key,V()));
		}

		void clear()
		{
			_ht.Clear();
		}

		void swap(const unordered_map<K,V>& m)
		{
			_ht.Swap(m._ht);
		}

		V& operator[](const K& key)
		{
			return (*(insert(ValueType(key, V())).first)).second;
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
			return _ht.bucket(ValueType(key,V()));
		}
	private:
		Hash<ValueType,KOFV> _ht;
	};
}
//void TestUnordered_map()
//{
//	My::unordered_map<string, string> m;
//
//	// 构造键值对的两种方式：pair结构体  make_pair
//	m.insert(pair<string, string>("宋江", "及时雨"));
//	m.insert(pair<string, string>("李逵", "铁牛"));
//	m.insert(pair<string, string>("林冲", "豹子头"));
//
//	m.insert(make_pair("武松", "行者"));
//
//	cout << m.Size() << endl;
//	cout << m.bucket_count() << endl;  // 桶的个数
//	cout << m.bucket_size(0) << endl;  // 0号桶中的元素个数
//	cout << m.bucket("宋江") << endl;   // 获取key所在的桶号
//
//	// key不能重复
//	m.insert(make_pair("李逵", "黑旋风"));
//	cout << m.Size() << endl;
//
//
//	// []：如果key存在，直接返回与key所对应的value
//	cout << m["李逵"] << endl;   // 给一个key，返回与该key对应的value
//	cout << m.Size() << endl;
//
//	// []: 如果key不存在，<key, 默认value>构建一个键值对，然后将其插入到容器中，返回默认的value
//	cout << m["鲁达"] << endl;
//	cout << m.Size() << endl;
//
//	m.erase("鲁达");
//	cout << m.Size() << endl;
//
//	m.clear();
//}