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
			return _ht.eraseunique(ValueType(key, V()));//Ĭ��V��ֵ��V()��ʾ
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
//	// �����ֵ�Ե����ַ�ʽ��pair�ṹ��  make_pair
//	m.insert(pair<string, string>("�ν�", "��ʱ��"));
//	m.insert(pair<string, string>("����", "��ţ"));
//	m.insert(pair<string, string>("�ֳ�", "����ͷ"));
//
//	m.insert(make_pair("����", "����"));
//
//	cout << m.Size() << endl;
//	cout << m.bucket_count() << endl;  // Ͱ�ĸ���
//	cout << m.bucket_size(0) << endl;  // 0��Ͱ�е�Ԫ�ظ���
//	cout << m.bucket("�ν�") << endl;   // ��ȡkey���ڵ�Ͱ��
//
//	// key�����ظ�
//	m.insert(make_pair("����", "������"));
//	cout << m.Size() << endl;
//
//
//	// []�����key���ڣ�ֱ�ӷ�����key����Ӧ��value
//	cout << m["����"] << endl;   // ��һ��key���������key��Ӧ��value
//	cout << m.Size() << endl;
//
//	// []: ���key�����ڣ�<key, Ĭ��value>����һ����ֵ�ԣ�Ȼ������뵽�����У�����Ĭ�ϵ�value
//	cout << m["³��"] << endl;
//	cout << m.Size() << endl;
//
//	m.erase("³��");
//	cout << m.Size() << endl;
//
//	m.clear();
//}