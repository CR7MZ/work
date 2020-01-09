#pragma once
//基于哈夫曼编码的压缩
#include"huffman tree.hpp"
#include<string>
#include<vector>
struct Char//用来保存字符的种类、出现的字数、以及这个字符新获取到的哈夫曼编码
{
	char _s;      //什么字符
	size_t _count;//字符出现的次数
	std::string _code;//字符哈夫曼编码
	Char(size_t count = 0)
		:_count(count)
	{}
	Char operator+(const Char& c)const//因为创建树，传入的是结构体，所以要自己给出+的方法
	{
		return Char(_count + c._count);//因为在创建树中，需要的不是次数，而是权值也就是结构体，所以需要返回结构体，而不是次数。
	}
	bool operator>(const Char& c)const//因为创建树，传入的是结构体，所以要自己给出>的方法
	{
		return _count > c._count;
	}
	bool operator==(const Char& c)const
	{
		return _count == c._count;
	}
};
class filecompressHuff
{
	typedef HuffManTreenode<Char> node;
public:
	filecompressHuff();//对_file数组进行初始化。
	void compressfile(const std::string& s);
	void UNcompressfile(const std::string& s);
private:
	void GetCode(HuffManTreenode<Char>* root);
private:
	std::vector<Char> _file;//文件中的字符上限256个，定义一个结构体数组，来保存每个字符的种类、出现次数、以及对应生成的Huffman编码
};