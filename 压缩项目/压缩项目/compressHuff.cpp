#include"fileCompressHuff.h"
#include"huffman tree.hpp"
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

	FILE* fIn = fopen("E:\\work\\work\\work\\压缩项目\\Debug\\1.txt", "rb");//打开一个文件，因为fopen只能接收C格式字符串，所以要转成C格式。
	if (nullptr == fIn)
	{
		assert(false);
		return;
	}
	getchar();
	unsigned char* buff = new unsigned char[1024];//用来保存从文件读出来的数据。
	int readsize = 0;
	while (true)//如果一次读不完，放在循环里读
	{
		readsize=fread(buff, 1, 1024, fIn);//一个字符占一个字节，一次读1024个，也就是1K的数据
		if (readsize == 0)//如果readsize==0说明读完了
			break;
		for (int i = 0; i < readsize; i++)//统计文件中读到所有字符，各自出现的次数。
			_file[buff[i]]._count++;//因为_file中有256个元素，所以可以看作ASKII码，
			                        //所以若要统计buff中字符出现的次数，只需要将buff里面的字符作为_file数组的下标，找到对应的
			                       //字符结构体，使其计数变量++即可。
	}
	//2.以字符的出现次数为权值创建哈夫曼树

	Huffmantree<Char> t;
	Char c;
	c._count = 0;
	t.CreatHuffmantree(_file,c);//此处传的是结构体数组，若要创建Huffman就要重载关于结构体的加法以及大于号。

	//3.获取每个字符的编码

	filecompressHuff::GetCode(t.GetROOT());

	//4.用获取到的字符编码重新改写原文件


	delete[] buff;
	fclose(fIn);
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
		node* cur = root;
		node* parent = cur->_parent;//parent为此时cur的父节点。
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