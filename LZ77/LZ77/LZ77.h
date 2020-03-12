#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include"HashTable.h"
#include<string>
#include<iostream>
using namespace std;


class LZ77
{
public:
	LZ77();
	~LZ77();
	void compressfile(const std::string& str);
	void Uncompressfile();
private:
	USH LongestMatch(USH matchhead,USH& curMatchDist,USH start);
	void WriteFlag(FILE* file, UCH& charflag, UCH& bitcount, bool islen);
	void Merge(FILE* file,ULL filesize);//将标记文件放到压缩数据文件中。合并起来
	void fillWin(FILE* FIn,size_t& lookahead,USH& start);  //填充数据
private:
	HashTable ht;
	UCH* pWin;
};