#include "fileCompressHuff.h"
#include"LZ77.h"
int main()
{
	LZ77 LZ;
	filecompressHuff f;
	LZ.Compressfile("1.txt");
	f.compressfile("2.lzp");
	f.UNcompressfile("3.lzp");
	LZ.Uncompressfile("4.lzp");
	system("pause");
	return 0;
}