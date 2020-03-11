#include"fileCompressHuff.h"
#include "Huffman Tree.hpp"
#include<assert.h>
#include<string>
filecompressHuff::filecompressHuff()
{
	_file.resize(256);
	for (int i = 0; i < 256; i++)
	{
		_file[i]._s = i;//��256���ַ�ͨ��ASKII��ʼ�������顣
		_file[i]._count = 0;
	}
}
void filecompressHuff::compressfile(const std::string& s)
{
	//1.ͳ��Դ�ļ���ÿ���ַ����ֵĴ���

	FILE* fIn = fopen(s.c_str(), "rb");//��һ���ļ�����Ϊfopenֻ�ܽ���C��ʽ�ַ���������Ҫת��C��ʽ��
	if (nullptr == fIn)
	{
		assert(false);
		return;
	}

	unsigned char* buff = new unsigned char[1024];//����������ļ������������ݡ�
	//��Ϊ�ַ���Χ��-128-127�������ǲ�����Ϊ�±�ģ����Բ������ַ���ASKii����Ϊ�����±꣬�������޷������͡�
	size_t readsize = 0;
	while (true)//���һ�ζ����꣬����ѭ�����
	{
		readsize=fread(buff, 1, 1024, fIn);//һ���ַ�ռһ���ֽڣ�һ�ζ�1024����Ҳ����1K������
		if (readsize == 0)//���readsize==0˵��������
			break;
		for (size_t i = 0; i < readsize; i++)//ͳ���ļ��ж��������ַ������Գ��ֵĴ�����
			_file[buff[i]]._count++;//��Ϊ_file����256��Ԫ�أ����Կ��Կ���ASKII�룬
			                        //������Ҫͳ��buff���ַ����ֵĴ�����ֻ��Ҫ��buff������ַ���Ϊ_file������±꣬�ҵ���Ӧ��
			                       //�ַ��ṹ�壬ʹ���������++���ɡ�
	}
	//2.���ַ��ĳ��ִ���ΪȨֵ������������

	Huffmantree<Char> t;
	t.CreatHuffmantree(_file, Char(0));//�˴������ǽṹ�����飬��Ҫ����Huffman��Ҫ���ع��ڽṹ��ļӷ��Լ����ںš�

	//3.��ȡÿ���ַ��ı���

	filecompressHuff::GetCode(t.GetROOT());

	//4.�û�ȡ�����ַ��������¸�дԭ�ļ�

	FILE* fout = fopen("3.lzp", "wb");//���������д���ݵ��ļ�������ѹ���ļ���
	if (nullptr == fout)
	{
		assert(false);
		return;
	}
	writehead(fout, s);//�ڽ�ѹ������д���ļ�ǰ������ѹ�õı�Ҫ��Ϣд���ļ���

	fseek(fIn, 0, SEEK_SET);
	char ch = 0;//����ÿһ���ֽ�8������λ�У�ÿ���ַ�����
	int count = 0;//ͳ��һ���ֽ��У��Ѿ��м�������λ�����˱���
	while (true)
	{
		readsize = fread(buff, 1, 1024, fIn);
		if (0 == readsize)
			break;

		//�����ַ��ı���Զ�ȡ���ļ����ݽ�����д��
		for (size_t i = 0; i < readsize; i++)
		{
			std::string strcode = _file[buff[i]]._code;//�ҵ�ԭ�ļ��У�ÿ���ַ���Ӧ�ı��롣
			for (size_t j = 0; j < strcode.size(); j++)//�����밴����λ����һ���ֽ��С�
				//���磺A��011   ��ô���ǽ���0��ʼ���ν�����ı��룬������������λ��
			{
				ch <<= 1;//ÿ�η���һ������λ�󣬽�����λ����1λ������������һ��
				if ('1' == strcode[j])
					ch |= 1;//����ʱ����ı���Ϊ1������ֽڰ�λ��1���ɣ�������ı���Ϊ0�����ô�����Ϊ�Ѿ���8������λ��ʼ��Ϊ0

				count++;
				if (8 == count)//���һ���ֽڷ����ˣ������ֱ��д��ѹ���ļ��С�
				{
					fputc(ch, fout);//fputc�����ļ���һ���ֽ�һ���ֽڵ�д��
					ch = 0;
					count = 0;
				}
			}
		}
	}
	//Ҳ�п��ܴ��ڣ����һ��ch�������һ���ֽڣ��п��ܲ���8������λ�����еı����Ѿ�д�꣬���������ͻ���ɽ�ѹ�ļ���Դ�ļ�����
	if (count < 8)
	{
		ch <<= (8 - count);//��ʱ����ֽ�д���˶��ٸ�����λ����������8-count������λ���ɡ�
		fputc(ch, fout);
	}

	delete[] buff;
	fclose(fIn);
	fclose(fout);
}

std::string filecompressHuff::getfileback(const std::string& filename)//�õ��ļ���׺
{
	return filename.substr(filename.rfind('.'));
}

void filecompressHuff::writehead(FILE* fout, const std::string & filename)//���ļ���׺���������м��������Ǳ����ַ����ִ��������ַ����ִ�����Ϣ
{
	assert(fout);

	//д���ļ��ĺ�׺
	std::string strhead;//���潫Ҫд��ѹ���ļ��еģ���ѹ��Ϣ��
	strhead += getfileback(filename);
	strhead += '\n';

	//д�����ַ���Ϣ����

	size_t linecount = 0;//�����ַ���Ϣ����
	std::string strcount;//���������ַ���Ϣ
	char strvalue[32] = { 0 };//����ת��Ϊ�ַ����͵Ĵ���
	for (int i = 0; i < 256; i++)
	{
		if (_file[i]._count)//���������Ϊ0
		{
			linecount++;
			strcount += _file[i]._s;//�����ַ�
			strcount += ':';
			_itoa(_file[i]._count, strvalue, 10);//���ַ�������תΪ�ַ����͡�
			strcount += strvalue;//�����ַ����ֵĴ���
			strcount += '\n';
		}
	}
	_itoa(linecount, strvalue, 10);
	strhead += strvalue;//�������Ž�ȥ
	strhead += '\n';
	strhead += strcount;//�ַ�����Ϣ

	fwrite(strhead.c_str(), 1, strhead.size(), fout);
}

void filecompressHuff::GetCode(HuffManTreenode<Char> *root)//��Ҷ�ӽ������ڵ��ҵ���Ҳ���Ǵ���������
{
	if (nullptr == root)
		return;
	GetCode(root->left);
	GetCode(root->right);
	if (root->left == nullptr&&root->right == nullptr)//ͨ���ݹ��ҵ�Ҷ�ӽ�㡣
	{
		std::string strcode;
		HuffManTreenode<Char>* parent = root->_parent;//parentΪ��ʱcur�ĸ��ڵ㡣
		HuffManTreenode<Char>* cur = root;
		while (parent)
		{
			if (cur == parent->left)//��cur��parent��ߣ�����֮ǰ�Ĺ涨Ϊ�ַ�'0'
				strcode += '0';
			else                   //��cur��parent�ұߣ�����֮ǰ�Ĺ涨Ϊ�ַ�'1'
				strcode += '1';
			cur = parent;
			parent = cur->_parent;
		}
		reverse(strcode.begin(), strcode.end());//��Ϊ�����Ǵ��������ҵı��룬���������Ҫ�����뷭ת����������һ���ַ��ı��롣
		_file[root->_weight._s]._code= strcode;//����Ӧ�ַ��ı��뱣����������Ϊ��ʱrootΪҶ�ӽ�㣬����ͨ��root�е��ַ�
		                                       //����_file�����У��ҵ��Ķ�Ӧ���ַ��������
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
	//1.��ȡ�ַ���Ϣ

	//�ļ���׺
	std::string fileback;
	ReadLine(FIn, fileback);

	//�ַ���Ϣ����
	std::string strcount;
	ReadLine(FIn, strcount);
	int linecount = atoi(strcount.c_str());

	//�ַ���Ϣ
	for (int i = 0; i < linecount; i++)
	{
		std::string strchcount;
		ReadLine(FIn, strchcount);
		if (strchcount.empty())//˵���������ǻ��У���ΪԴ�ļ��п϶�Ҳ�л��С�
		{
			strchcount += '\n';
			ReadLine(FIn, strchcount);//�ٶ�һ��
		}
		//�ַ���Ϣ��A:1
		_file[(unsigned char)strchcount[0]]._count = atoi(strchcount.c_str() + 2);//+2��������ǰ�����ַ���ֱ���ҵ�������ͨ���ַ���ASKII��ֵ�����ַ�������±꣬�ҵ��ַ��Ľṹ�塣
	}
	//2.�ع�Huffman��
	Huffmantree<Char> t;
	t.CreatHuffmantree(_file, Char(0));

	FILE* fout = fopen("4.lzp","wb");//��ѹ���ļ�
	//3.��ѹ��
	char* buff = new char[1024];
	HuffManTreenode<Char>* cur = t.GetROOT();
	size_t filesize = cur->_weight._count;//�ļ��ܴ�С����ΪHuffman���ڵ��ȨֵΪ�ļ����ܴ�С��
	size_t uncount = 0;//��¼��ѹ���ֽ���
	while (true)
	{
		size_t rdsize = fread(buff, 1, 1024, FIn);
		if (rdsize == 0)
			break;
		for (size_t i = 0; i < rdsize; i++)//����ÿ���ֽ�
		{
			if (cur->left == nullptr&&cur->right == nullptr)
			{
				if (uncount == filesize)
					break;
				cur = t.GetROOT();
			}
			//ֻ�轫һ���ֽ��е�8������λ��������
			for (int pos = 0; pos < 8; pos++)
			{
				if (buff[i] & 0x80)//�ж�����ֽڵ����λ��1����0��0x80--->1000 0000
					cur = cur->right;
				else
					cur = cur->left;

				buff[i] <<= 1;
				if (cur->left == nullptr&&cur->right == nullptr)//�ڸ��ڵ�
				{
					uncount++;
					fputc(cur->_weight._s, fout);//��ͨ�������ѹ�������ַ���д���ѹ���ļ��С�
					if (uncount == filesize)//��ѹ�ֽ�����ѹ���ļ��ֽ�����ȣ�˵����ѹ���ˡ�
						break;
					cur = t.GetROOT();//һ���ַ���ѹ��cur����ָ����ڵ㣬����ͨ��������Ҷ�ӽ�㣬��ѹ���ַ���
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
	while (!feof(FIn))//���ļ�ĩβ�˳�
	{
		char ch = fgetc(FIn);
		if (ch == '\n')
			break;

		strInfo += ch;
	}
}