#pragma once
//���ڹ����������ѹ��
#include"huffman tree.hpp"
#include<string>
#include<vector>
struct Char//���������ַ������ࡢ���ֵ��������Լ�����ַ��»�ȡ���Ĺ���������
{
	char _s;      //ʲô�ַ�
	size_t _count;//�ַ����ֵĴ���
	std::string _code;//�ַ�����������
	Char(size_t count = 0)
		:_count(count)
	{}
	Char operator+(const Char& c)const//��Ϊ��������������ǽṹ�壬����Ҫ�Լ�����+�ķ���
	{
		return Char(_count + c._count);//��Ϊ�ڴ������У���Ҫ�Ĳ��Ǵ���������ȨֵҲ���ǽṹ�壬������Ҫ���ؽṹ�壬�����Ǵ�����
	}
	bool operator>(const Char& c)const//��Ϊ��������������ǽṹ�壬����Ҫ�Լ�����>�ķ���
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
	filecompressHuff();//��_file������г�ʼ����
	void compressfile(const std::string& s);
	void UNcompressfile(const std::string& s);
private:
	void GetCode(HuffManTreenode<Char>* root);
private:
	std::vector<Char> _file;//�ļ��е��ַ�����256��������һ���ṹ�����飬������ÿ���ַ������ࡢ���ִ������Լ���Ӧ���ɵ�Huffman����
};