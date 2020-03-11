#pragma once 
#include"HashTable.h"
#include<string>
#include<iostream>
using namespace std;


const USH LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1; //现行缓冲区剩余字符最小个数
const USH MAX_DIST = WSIZE - LOOKAHEAD;    //查找缓冲区最大查找距离

class LZ77
{
public:
	LZ77();
	~LZ77();
	void Compressfile(const std::string& str);
	void Uncompressfile(const std::string& str);
	USH LongestMatch(USH matchhead,USH& curMatchDist);
	void WriteFlag(FILE* file, UCH& charflag, UCH& bitcount, bool islen);
	void Merge(FILE* file,ULL filesize);//将标记文件放到压缩数据文件中。合并起来
	void fillWin(FILE* FIn,size_t& lookahead);  //填充数据
private:
	HashTable ht;
	UCH* pWin;
	USH start;
};