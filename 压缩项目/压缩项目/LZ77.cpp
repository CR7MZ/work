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
		cout << "���ļ�ʧ�ܣ�����" << endl;
		return;
	}

	//��ȡ�ļ���С
	fseek(FIn, 0, SEEK_END);
	ULL FileSize = ftell(FIn);

	//����ļ���СС��MIN_MATCH����Ҫѹ����
	if (FileSize <= MIN_MATCH)
	{
		cout << "�ļ���ͬѹ��" << endl;
		return;
	}

	//���ļ��ж�ȡ64K�����ݵ�pWin��
	fseek(FIn, 0, SEEK_SET);
	size_t LookAhead = fread(pWin, 1, 2 * WSIZE,FIn);

	USH hashaddr = 0;
	for (int i = 0; i < MIN_MATCH - 1; i++)
		ht.HashFunc(hashaddr, pWin[i]);

	FILE* FOut = fopen("2.lzp", "wb");
	assert(FOut);

	USH matchhead = 0;
	USH curMatchLength = 0; //����
	USH curMatchDist = 0;   //����

	//�����ַ������볤�ȶ�
	UCH chflag = 0;
	UCH bitcount = 0;
	bool IS = false;
	FILE* FE = fopen("3.txt", "wb");
	assert(FE);

	//LookAhead��ʾ���Ի������ĸ���
	while (LookAhead)
	{
		//��һ���ַ��������ϣ����
		ht.insert(hashaddr, pWin[start + 2],start, matchhead);

		curMatchLength = 0;
		curMatchDist = 0;

		//��ȡƥ����ͷ������������ֵ
		if (matchhead)//˵��ƥ��
		{
			curMatchLength = LongestMatch(matchhead, curMatchDist);
		}
		if (curMatchLength < MIN_MATCH)//���ƥ�䳤��С����С���Ȼ���û�ҵ�ƥ�䣬��ԭ�ַ�д��ѹ���ļ��У�������һ�����ַ���
		{
			fputc(pWin[start], FOut);

			WriteFlag(FE, chflag, bitcount, false);//д����������ԭ�ַ������ǳ��Ⱦ���ԡ�
			++start;
			--LookAhead;
		}
		else                //��ƥ�䳤�Ⱦ���д��ѹ���ļ���
		{
			//д�볤��
			UCH res = curMatchLength - 3;//��Ϊѹ������Ϊ3~258��һ���ֽڷŲ��£�����ֻ�ܽ�����-3��һ���ֽڱ��棬����ѹ��ʱ��+3���ɡ�
			fputc(res, FOut);
			//д�����
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, FOut);

			WriteFlag(FE, chflag, bitcount, true);//д����������ԭ�ַ������ǳ��Ⱦ���ԡ�

			// �������л�������ʣ����ֽ���
			LookAhead -= curMatchLength;

			// ���Ѿ�ƥ����ַ�����������һ�齫����뵽��ϣ����
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
	
 
	fclose(FE);//����ļ�

	Merge(FOut, FileSize);//��ѹ�����ݡ�������ݡ�����������ֽ�����Դ�ļ���С
	fclose(FIn); //ԭ�ļ�
	fclose(FOut);//ѹ���ļ�
	if (remove("3.txt") != 0)
	{
		std::cout << "remove error " << std::endl;
	}
}

void LZ77::fillWin(FILE* FIn, size_t& lookahead)
{
	if (start >= WSIZE)
	{
		//���Ҵ��ڵ����ݰ��Ƶ���
		memcpy(pWin, pWin + WSIZE, WSIZE);
		memset(pWin + WSIZE, 0, WSIZE);
		start -= WSIZE;

		//���¹�ϣ��
		ht.Update();

		//������ݣ����Ұ벿��
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
	UCH curMatchlen = 0;//һ��ƥ��ĳ���
	UCH MaxMatchlen = 0;//���ĳ���
	USH limit = start > MAX_DIST ? start - MAX_DIST : 0;
	UCH MaxMatchCount = 255;
	USH curMamstart = 0;//������һ��������ƥ������ꡣ

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
		//һ��ƥ�����
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

	//��ѹ���ļ���ֻ��ȡѹ������
	FILE* FIn=fopen(path.c_str(), "rb");
	if (FIn == nullptr)
	{
		cout << "��ѹʧ�ܣ�����" << endl;
		return;
	}

	FILE* Cur = fopen(path.c_str(), "rb");//�Ӻ����ȡ����ѹ����Ϣ
	assert(Cur);

	//��ȡԴ�ļ���С
	ULL filesize=0;
	fseek(Cur, 0 - sizeof(filesize) , SEEK_END);
	fread(&filesize, sizeof(filesize), 1, Cur);

	//��ȡ����ֽ�����
	size_t flagsize = 0;
	fseek(Cur, 0 - sizeof(filesize) - sizeof(flagsize), SEEK_END);
	fread(&flagsize, sizeof(flagsize), 1, Cur);
	
	//����ȡ�����Ϣ��ָ��cur�Ƶ������Ϣ��ǰ��
	fseek(Cur, 0 - sizeof(filesize) - sizeof(flagsize) - flagsize, SEEK_END);

	FILE* Fout = fopen("5.txt", "wb");//��ѹ���ļ�

	FILE* FR = fopen("5.txt", "rb");

	UCH bitcount = 0;
	UCH chflag = 0;
	ULL count = 0;//������ڵ���ԭ�ļ���С��˵����ѹ��
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
			//��ˢ����������Ϊ�������ļ���д��������д���������У������������˲�д���ļ�������������Ҫ����ˢ�»�������
			//����ԭ�ַ�д�����������ǳ��Ⱦ���Խ�ѹ�󣬾ͻ�Ϊ�ո�

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