#include"LZ77.h"
#include<assert.h>
LZ77::LZ77()
	:pWin(new UCH[WSIZE*2])
	, ht(WSIZE)
	, start(0)
{}
LZ77::~LZ77()
{
	delete[] pWin;
	pWin = nullptr;
}
void LZ77::Compressfile(const std::string& filepath)
{
	FILE* FIn = fopen(filepath.c_str(), "rb");
	if (nullptr == FIn)
	{
		cout << "打开文件失败！！！" << endl;
		return;
	}

	//获取文件大小
	fseek(FIn, 0, SEEK_END);
	ULL FileSize = ftell(FIn);

	//如果文件大小小于MIN_MATCH则不需要压缩。
	if (FileSize <= MIN_MATCH)
	{
		cout << "文件不同压缩" << endl;
		return;
	}

	//从文件中读取64K的内容到pWin中
	fseek(FIn, 0, SEEK_SET);
	size_t LookAhead = fread(pWin, 1, 2 * WSIZE,FIn);

	USH hashaddr = 0;
	for (int i = 0; i < MIN_MATCH - 1; i++)
		ht.HashFunc(hashaddr, pWin[i]);

	FILE* FOut = fopen("2.lzp", "wb");
	assert(FOut);

	USH matchhead = 0;
	USH curMatchLength = 0; //长度
	USH curMatchDist = 0;   //距离

	//区分字符、距离长度对
	UCH chflag = 0;
	UCH bitcount = 0;
	bool IS = false;
	FILE* FE = fopen("3.txt", "wb");
	assert(FE);

	//LookAhead表示线性缓冲区的个数
	while (LookAhead)
	{
		//将一个字符串插入哈希表中
		ht.insert(hashaddr, pWin[start + 2],start, matchhead);

		curMatchLength = 0;
		curMatchDist = 0;

		//获取匹配链头，看其是有数值
		if (matchhead)//说明匹配
		{
			curMatchLength = LongestMatch(matchhead, curMatchDist);
		}
		if (curMatchLength < MIN_MATCH)//如果匹配长度小于最小长度或者没找到匹配，将原字符写入压缩文件中，进行下一个在字符的
		{
			fputc(pWin[start], FOut);

			WriteFlag(FE, chflag, bitcount, false);//写入标记来区分原字符，还是长度距离对。
			++start;
			--LookAhead;
		}
		else                //将匹配长度距离写入压缩文件中
		{
			//写入长度
			UCH res = curMatchLength - 3;//因为压缩长度为3~258，一个字节放不下，所以只能将长度-3用一个字节保存，当解压的时候+3即可。
			fputc(res, FOut);
			//写入距离
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, FOut);

			WriteFlag(FE, chflag, bitcount, true);//写入标记来区分原字符，还是长度距离对。

			// 更新先行缓冲区中剩余的字节数
			LookAhead -= curMatchLength;

			// 将已经匹配的字符串按照三个一组将其插入到哈希表中
			--curMatchLength;
			while (curMatchLength)
			{
				start++;
				ht.insert(hashaddr, pWin[start + 2], start, matchhead);
				--curMatchLength;
			}
			start++;
		}
		if (LookAhead <= LOOKAHEAD)
			fillWin(FIn,LookAhead);
	}
	if (bitcount > 0 && bitcount < 8)
	{
		chflag <<= (8 - bitcount);
		fputc(chflag, FE);
	}
	
 
	fclose(FE);//标记文件

	Merge(FOut, FileSize);//将压缩数据、标记数据、标记数据总字节数、源文件大小
	fclose(FIn); //原文件
	fclose(FOut);//压缩文件
	if (remove("3.txt") != 0)
	{
		std::cout << "remove error " << std::endl;
	}
}

void LZ77::fillWin(FILE* FIn, size_t& lookahead)
{
	if (start >= WSIZE)
	{
		//将右窗口的数据搬移到左窗
		memcpy(pWin, pWin + WSIZE, WSIZE);
		memset(pWin + WSIZE, 0, WSIZE);
		start -= WSIZE;

		//更新哈希表
		ht.Update();

		//填充数据，想右半部分
		if (!feof(FIn))
			lookahead += fread(pWin + WSIZE, 1, WSIZE, FIn);
	}
}

void LZ77::Merge(FILE* fout, ULL filesize)
{
	FILE* finf = fopen("3.txt", "rb");

	size_t flagsize = 0;
	UCH* PreadBuff = new UCH[1024];
	while (true)
	{
		size_t rdsize = fread(PreadBuff, 1, 1024, finf); 
		if (rdsize == 0)
			break;
		fwrite(PreadBuff, 1, rdsize, fout); 
		flagsize += rdsize;
	}
	fwrite(&flagsize, sizeof(flagsize), 1, fout);
	fwrite(&filesize, sizeof(filesize), 1, fout);
	delete[] PreadBuff;
	fclose(finf);
}

void LZ77::WriteFlag(FILE* file, UCH& charflag, UCH& bitcount, bool islen )
{
	charflag <<= 1;

	if (islen)
		charflag |= 1;
	bitcount++;
	if (bitcount == 8)
	{
		fputc(charflag, file);
		charflag = 0;
		bitcount = 0;
	}
}
USH LZ77::LongestMatch(USH matchhead, USH& curMatchDist)
{
	UCH curMatchlen = 0;//一次匹配的长度
	UCH MaxMatchlen = 0;//最大的长度
	USH limit = start > MAX_DIST ? start - MAX_DIST : 0;
	UCH MaxMatchCount = 255;
	USH curMamstart = 0;//保存查找缓冲区中最长匹配的坐标。

	do
	{
		UCH* pstart = pWin + start;
		UCH* pend = pstart + MAX_MATCH;

		UCH* pMatchstart = pWin + matchhead;

		curMatchlen = 0;
		while (pstart < pend && *pstart == *pMatchstart)
		{
			curMatchlen++;
			pstart++;
			pMatchstart++;
		}
		//一次匹配结束
		if (curMatchlen > MaxMatchlen)
		{
			MaxMatchlen = curMatchlen;
			curMamstart = matchhead;
		}
	} while ((matchhead = ht.Getnext(matchhead)) > limit&& MaxMatchCount--);
	curMatchDist = start - curMamstart;
	return MaxMatchlen;
}

void LZ77::Uncompressfile(const string& path)
{

	//打开压缩文件，只获取压缩数据
	FILE* FIn=fopen(path.c_str(), "rb");
	if (FIn == nullptr)
	{
		cout << "解压失败！！！" << endl;
		return;
	}

	FILE* Cur = fopen(path.c_str(), "rb");//从后面获取其他压缩信息
	assert(Cur);

	//读取源文件大小
	ULL filesize=0;
	fseek(Cur, 0 - sizeof(filesize) , SEEK_END);
	fread(&filesize, sizeof(filesize), 1, Cur);

	//读取标记字节总数
	size_t flagsize = 0;
	fseek(Cur, 0 - sizeof(filesize) - sizeof(flagsize), SEEK_END);
	fread(&flagsize, sizeof(flagsize), 1, Cur);
	
	//将读取标记信息的指针cur移到标记信息的前面
	fseek(Cur, 0 - sizeof(filesize) - sizeof(flagsize) - flagsize, SEEK_END);

	FILE* Fout = fopen("5.txt", "wb");//解压缩文件

	FILE* FR = fopen("5.txt", "rb");

	UCH bitcount = 0;
	UCH chflag = 0;
	ULL count = 0;//如果大于等于原文件大小，说明解压完
	while (count<filesize)
	{
		if (0 == bitcount)
		{
			chflag = fgetc(Cur);
			bitcount = 8;
		}
		if (chflag & 0x80)
		{
			USH len = fgetc(FIn) + 3;
			USH Dist = 0;
			fread(&Dist, sizeof(Dist), 1, FIn);

			fflush(Fout);
			//冲刷缓冲区，因为我们往文件里写的数据先写到缓冲区中，当缓冲区满了才写入文件，所以我们需要自行刷新缓冲区。
			//否则，原字符写入正常，但是长度距离对解压后，就会为空格。

			count += len;

			fseek(FR, 0 - Dist, SEEK_END);
			UCH ch=0;
			while (len)
			{
				ch = fgetc(FR);
				fputc(ch, Fout);
				len--;
				fflush(Fout);
			}
		}
		else
		{
			UCH ch = fgetc(FIn);
			fputc(ch, Fout);
			count += 1;
		}
		chflag <<= 1;
		bitcount--;
	}
	fclose(FIn);
	fclose(Fout);
	fclose(FR);
	fclose(Cur);
}