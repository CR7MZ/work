#pragma once

#include "RBTree.hpp"
#include <string>
#include <iostream>

namespace My
{
	template<class K,class V>
	class map
	{
		typedef pair<K, V> ValuType;
	public:
		struct KOFV
		{
		public:
			const K& operator()(const ValuType& v)const
			{
				return v.first;
			}
		};
	private:
		//告诉编译器Iterator是自己定义的类型，而不是静态成员
		typename typedef RBTree<ValuType, KOFV>::Iterator iterator;
	public:
		map()
			:rb()
		{}

		iterator begin()
		{
			return rb.begin();
		}

		iterator end()
		{
			return rb.end();
		}

		bool empty()const
		{
			return rb.empty();
		}

		size_t size()
		{
			return rb.size();
		}

		pair<iterator, bool> insert(const ValuType& v)
		{
			return rb.insert(v);
		}

		iterator find(const K& key)
		{
			return rb.find(ValuType(key, V()));
		}

		V& operator[](const K& key)
		{
			return (*(rb.insert(ValuType(key, V())).first)).second;
		}
	private:
		RBTree<ValuType,KOFV> rb;
	};
}
void TestMap()
{
	My::map<string, string> m;
	m.insert(pair<string, string>("apple", "苹果"));
	m.insert(make_pair("orange", "句子"));

	cout << m["apple"] << endl;
	cout << m.size() << endl;

	m["peach"];
	cout << m.size() << endl;

	m.insert(make_pair("orange", "句子"));

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
	cout << endl;
	m.find("orange");
}