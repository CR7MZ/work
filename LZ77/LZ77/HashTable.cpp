#include"HashTable.h"
#include<string.h>
HashTable::HashTable(USH size)
	:prev(new USH[size*2])
	,head(prev+size)
{
	memset(prev, 0, size * 2 * sizeof(USH));
}
void HashTable::insert(USH& hashaddr, UCH ch, USH pos, USH& matchhead)
{
	HashFunc(hashaddr, ch);//º∆À„π˛œ£µÿ÷∑

	matchhead = head[hashaddr];
	prev[pos&HASH_MASK] = head[hashaddr];
	head[hashaddr]=pos;
}

void HashTable::HashFunc(USH& hashaddr, UCH ch)
{
	hashaddr = (((hashaddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}
USH HashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}

USH  HashTable::Getnext(USH matchhead)
{
	return prev[matchhead&HASH_MASK];
}