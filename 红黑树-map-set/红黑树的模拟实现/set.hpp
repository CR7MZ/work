#pragma once

#include "RBTree.hpp"
#include <string>
#include <iostream>

namespace My
{
	template<class K>
	class set
	{
		typedef K ValuType;
	public:
		struct KOFV
		{
		public:
			const K& operator()(const ValuType& v)const
			{
				return v;
			}
		};
	private:
		//告诉编译器Iterator是自己定义的类型，而不是静态成员
		typename typedef RBTree<ValuType, KOFV>::Iterator iterator;
	public:
		set()
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
			return rb.find(key);
		}

	private:
		RBTree<ValuType, KOFV> rb;
	};
}
void TestSet()
{
	My::set<string> s;
	s.insert("apple");
	s.insert("xcfdsf");
	s.insert("peach");
	s.insert("cat");
	cout << s.size() << endl;

	s.insert("apple");
	cout << s.size() << endl;

	if (s.find("cat") != s.end())
	{
		cout << "In" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	if (s.find("jvds") != s.end())
	{
		cout << "In" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}