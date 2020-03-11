#include"fileCompressHuff.h"
#include "Huffman Tree.hpp"
#include<assert.h>
#include<string>
filecompressHuff::filecompressHuff()
{
	_file.resize(256);
	for (int i = 0; i < 256; i++)
	{
		_file[i]._s = i;//将256个字符通过ASKII初始化给数组。
		_file[i]._count = 0;
	}
}
void filecompressHuff::compressfile(const std::string& s)
{
	//1.统计源文件中每个字符出现的次数

	FILE* fIn = fopen(s.c_str(), "rb");//打开一个文件，因为fopen只能接收C格式字符串，所以要转成C格式。
	if (nullptr == fIn)
	{
		assert(false);
		return;
	}

	unsigned char* buff = new unsigned char[1024];//用来保存从文件读出来的数据。
	//因为字符范围是-128-127，负数是不能作为下标的，所以不能用字符的ASKii码作为数组下标，所以用无符号类型。
	size_t readsize = 0;
	while (true)//如果一次读不完，放在循环里读
	{
		readsize=fread(buff, 1, 1024, fIn);//一个字符占一个字节，一次读1024个，也就是1K的数据
		if (readsize == 0)//如果readsize==0说明读完了
			break;
		for (size_t i = 0; i < readsize; i++)//统计文件中读到所有字符，各自出现的次数。
			_file[buff[i]]._count++;//因为_file中有256个元素，所以可以看作ASKII码，
			                        //所以若要统计buff中字符出现的次数，只需要将buff里面的字符作为_file数组的下标，找到对应的
			                       //字符结构体，使其计数变量++即可。
	}
	//2.以字符的出现次数为权值创建哈夫曼树

	Huffmantree<Char> t;
	t.CreatHuffmantree(_file, Char(0));//此处传的是结构体数组，若要创建Huffman就要重载关于结构体的加法以及大于号。

	//3.获取每个字符的编码

	filecompressHuff::GetCode(t.GetROOT());

	//4.用获取到的字符编码重新改写原文件

	FILE* fout = fopen("3.lzp", "wb");//用来存放重写内容的文件，就是压缩文件。
	if (nullptr == fout)
	{
		assert(false);
		return;
	}
	writehead(fout, s);//在将压缩数据写入文件前，将解压用的必要信息写入文件。

	fseek(fIn, 0, SEEK_SET);
	char ch = 0;//保存每一个字节8个比特位中，每个字符编码
	int count = 0;//统计一个字节中，已经有几个比特位被放了编码
	while (true)
	{
		readsize = fread(buff, 1, 1024, fIn);
		if (0 == readsize)
			break;

		//根据字符的编码对读取的文件内容进行重写。
		for (size_t i = 0; i < readsize; i++)
		{
			std::string strcode = _file[buff[i]]._code;//找到原文件中，每个字符对应的编码。
			for (size_t j = 0; j < strcode.size(); j++)//将编码按比特位放入一个字节中。
				//例如：A：011   那么就是将从0开始依次将后面的编码，放入三个比特位中
			{
				ch <<= 1;//每次放入一个比特位后，将比特位左移1位，继续放入下一个
				if ('1' == strcode[j])
					ch |= 1;//若此时放入的编码为1，这个字节按位或1即可，若放入的编码为0，则不用处理，因为已经将8个比特位初始化为0

				count++;
				if (8 == count)//如果一个字节放满了，将这个直接写入压缩文件中。
				{
					fputc(ch, fout);//fputc是向文件中一个字节一个字节的写。
					ch = 0;
					count = 0;
				}
			}
		}
	}
	//也有可能存在，最后一次ch（在最后一个字节）中可能不满8个比特位，所有的编码已经写完，如果不处理就会造成解压文件与源文件有误差。
	if (count < 8)
	{
		ch <<= (8 - count);//此时这个字节写入了多少个比特位，让其左移8-count个比特位即可。
		fputc(ch, fout);
	}

	delete[] buff;
	fclose(fIn);
	fclose(fout);
}

std::string filecompressHuff::getfileback(const std::string& filename)//得到文件后缀
{
	return filename.substr(filename.rfind('.'));
}

void filecompressHuff::writehead(FILE* fout, const std::string & filename)//将文件后缀、行数（有几行内容是保存字符出现次数）、字符出现次数信息
{
	assert(fout);

	//写入文件的后缀
	std::string strhead;//保存将要写入压缩文件中的，解压信息。
	strhead += getfileback(filename);
	strhead += '\n';

	//写包含字符信息行数

	size_t linecount = 0;//包含字符信息行数
	std::string strcount;//用来保存字符信息
	char strvalue[32] = { 0 };//接收转换为字符类型的次数
	for (int i = 0; i < 256; i++)
	{
		if (_file[i]._count)//如果次数不为0
		{
			linecount++;
			strcount += _file[i]._s;//放入字符
			strcount += ':';
			_itoa(_file[i]._count, strvalue, 10);//将字符次数，转为字符类型。
			strcount += strvalue;//放入字符出现的次数
			strcount += '\n';
		}
	}
	_itoa(linecount, strvalue, 10);
	strhead += strvalue;//把行数放进去
	strhead += '\n';
	strhead += strcount;//字符的信息

	fwrite(strhead.c_str(), 1, strhead.size(), fout);
}

void filecompressHuff::GetCode(HuffManTreenode<Char> *root)//从叶子结点向根节点找到，也就是从下向上找
{
	if (nullptr == root)
		return;
	GetCode(root->left);
	GetCode(root->right);
	if (root->left == nullptr&&root->right == nullptr)//通过递归找到叶子结点。
	{
		std::string strcode;
		HuffManTreenode<Char>* parent = root->_parent;//parent为此时cur的父节点。
		HuffManTreenode<Char>* cur = root;
		while (parent)
		{
			if (cur == parent->left)//若cur在parent左边，根据之前的规定为字符'0'
				strcode += '0';
			else                   //若cur在parent右边，根据之前的规定为字符'1'
				strcode += '1';
			cur = parent;
			parent = cur->_parent;
		}
		reverse(strcode.begin(), strcode.end());//因为我们是从下向上找的编码，所以最后需要将编码翻转，才是我们一个字符的编码。
		_file[root->_weight._s]._code= strcode;//将对应字符的编码保存起来，因为此时root为叶子结点，所以通过root中的字符
		                                       //来在_file数组中，找到的对应的字符来存编码
	}
}

void filecompressHuff::UNcompressfile(const std::string& s)
{
	FILE* FIn = fopen(s.c_str(), "rb");
	if (nullptr == FIn)
	{
		assert(false);
		return;
	}
	//1.获取字符信息

	//文件后缀
	std::string fileback;
	ReadLine(FIn, fileback);

	//字符信息行数
	std::string strcount;
	ReadLine(FIn, strcount);
	int linecount = atoi(strcount.c_str());

	//字符信息
	for (int i = 0; i < linecount; i++)
	{
		std::string strchcount;
		ReadLine(FIn, strchcount);
		if (strchcount.empty())//说明读到的是换行，因为源文件中肯定也有换行。
		{
			strchcount += '\n';
			ReadLine(FIn, strchcount);//再读一行
		}
		//字符信息是A:1
		_file[(unsigned char)strchcount[0]]._count = atoi(strchcount.c_str() + 2);//+2代表跳过前两个字符，直接找到次数，通过字符的ASKII码值当做字符数组的下标，找到字符的结构体。
	}
	//2.重构Huffman树
	Huffmantree<Char> t;
	t.CreatHuffmantree(_file, Char(0));

	FILE* fout = fopen("4.lzp","wb");//解压缩文件
	//3.解压缩
	char* buff = new char[1024];
	HuffManTreenode<Char>* cur = t.GetROOT();
	size_t filesize = cur->_weight._count;//文件总大小，因为Huffman根节点的权值为文件的总大小。
	size_t uncount = 0;//记录解压了字节数
	while (true)
	{
		size_t rdsize = fread(buff, 1, 1024, FIn);
		if (rdsize == 0)
			break;
		for (size_t i = 0; i < rdsize; i++)//处理每个字节
		{
			if (cur->left == nullptr&&cur->right == nullptr)
			{
				if (uncount == filesize)
					break;
				cur = t.GetROOT();
			}
			//只需将一个字节中的8个比特位单独处理
			for (int pos = 0; pos < 8; pos++)
			{
				if (buff[i] & 0x80)//判断这个字节的最高位是1或者0，0x80--->1000 0000
					cur = cur->right;
				else
					cur = cur->left;

				buff[i] <<= 1;
				if (cur->left == nullptr&&cur->right == nullptr)//在根节点
				{
					uncount++;
					fputc(cur->_weight._s, fout);//将通过编码解压出来的字符，写入解压缩文件中。
					if (uncount == filesize)//解压字节数和压缩文件字节数相等，说明解压完了。
						break;
					cur = t.GetROOT();//一个字符解压后，cur继续指向根节点，继续通过编码找叶子结点，解压出字符。
				}
			}
		}
	}
	delete[] buff;
	fclose(FIn);
	fclose(fout);

}
void filecompressHuff::ReadLine(FILE* FIn,  std::string& strInfo)
{
	assert(FIn);
	while (!feof(FIn))//到文件末尾退出
	{
		char ch = fgetc(FIn);
		if (ch == '\n')
			break;

		strInfo += ch;
	}
}