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
	void Merge(FILE* file,ULL filesize);//������ļ��ŵ�ѹ�������ļ��С��ϲ�����
	void fillWin(FILE* FIn,size_t& lookahead,USH& start);  //�������
private:
	HashTable ht;
	UCH* pWin;
};