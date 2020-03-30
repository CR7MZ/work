#include "fileCompressHuff.h"
#include "LZ77.h"
#include <windows.h>
#include <time.h>
int main()
{
	LZ77 LZ;
	filecompressHuff f;
	time_t begin, end;
	begin = time(NULL);
	LZ.Compressfile("1.txt");
	f.compressfile("2.lzp");
	f.UNcompressfile("3.lzp");
	LZ.Uncompressfile("4.lzp");
	end = time(NULL);
	cout << end - begin << endl;
	system("pause");
	return 0;
}