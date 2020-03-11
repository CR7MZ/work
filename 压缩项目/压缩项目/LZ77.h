#pragma once 
#include"HashTable.h"
#include<string>
#include<iostream>
using namespace std;


const USH LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1; //���л�����ʣ���ַ���С����
const USH MAX_DIST = WSIZE - LOOKAHEAD;    //���һ����������Ҿ���

class LZ77
{
public:
	LZ77();
	~LZ77();
	void Compressfile(const std::string& str);
	void Uncompressfile(const std::string& str);
	USH LongestMatch(USH matchhead,USH& curMatchDist);
	void WriteFlag(FILE* file, UCH& charflag, UCH& bitcount, bool islen);
	void Merge(FILE* file,ULL filesize);//������ļ��ŵ�ѹ�������ļ��С��ϲ�����
	void fillWin(FILE* FIn,size_t& lookahead);  //�������
private:
	HashTable ht;
	UCH* pWin;
	USH start;
};