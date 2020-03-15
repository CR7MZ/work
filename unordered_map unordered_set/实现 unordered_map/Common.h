#pragma once 

#include<string>

size_t GetNextPrime(size_t cap);

template<class T>
class DFf
{
public:
	size_t operator()(const T& data)
	{
		return data;
	}
};

class DFstr
{
public:
	size_t operator()(const std::string& str)
	{
		return Func(str.c_str());
	}
private:
	size_t Func(const char* str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};