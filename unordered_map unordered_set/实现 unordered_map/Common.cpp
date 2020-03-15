#include"Common.h"

const int PRIMECOUNT = 28;
const size_t primeList[PRIMECOUNT] = {
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};//素数

size_t GetNextPrime(size_t cap)//通过童虎设置的容量，在素数的数组中，找一个只大一点点的素数，返回。
//比如用户给的容量是10，我们就选用53来作为哈希表的容量。
{
	for (auto e : primeList)
		if (e > cap)
			return e;
	return primeList[PRIMECOUNT];
}