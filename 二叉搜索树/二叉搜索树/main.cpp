#include<iostream>
using namespace std;
template<class T>
struct BSTNode
{
	BSTNode(const T& data)
		:left(nullptr)
		, right(nullptr)
		, _data(data)
	BSTNode<T>* left;
	BSTNode<T>* right;
	T _data;
};