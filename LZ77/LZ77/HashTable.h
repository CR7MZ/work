#pragma once

#include<vector>

typedef unsigned char UCH;
typedef unsigned short USH;
typedef unsigned long long ULL;

const USH  WSIZE = 32 * 1024;
const USH HASH_BITS = 15;//��ϣ��ַ�ж��ٸ�����λ
const USH HASH_SIZE = (1 << 15);//��ϣ��ַ����
const USH HASH_MASK = HASH_SIZE - 1;

const USH MIN_MATCH = 3;
const USH MAX_MATCH = 258;

class HashTable
{
public:
	HashTable(USH size);
	~HashTable();
	void insert(USH& matchhead, UCH ch, USH pos, USH& hashaddr);
	void HashFunc(USH& hashaddr, UCH ch);
	USH Getnext(USH matchhead);
	void Update();
private:
	USH H_SHIFT();
private:
	USH* prev;
	USH* head;
};