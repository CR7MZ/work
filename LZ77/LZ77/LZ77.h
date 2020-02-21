#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include"HashTable.h"
#include<string>
#include<iostream>
using namespace std;

const USH  WSIZE = 32 * 1024;
const USH LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1; //���л�����ʣ���ַ���С����
const USH MAX_DIST = WSIZE - LOOKAHEAD;    //���һ����������Ҿ���

class LZ77
{
public:
	LZ77();
	~LZ77();
	void compressfile(const std::string& str);
	void Uncompressfile();
	USH LongestMatch(USH matchhead,USH& curMatchDist);
	void WriteFlag(FILE* file, UCH& charflag, UCH& bitcount, bool islen);
private:
	HashTable ht;
	UCH* pWin;
	USH start;
};