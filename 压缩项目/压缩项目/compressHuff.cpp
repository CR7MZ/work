#include"fileCompressHuff.h"
#include"huffman tree.hpp"
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

	FILE* fIn = fopen("E:\\work\\work\\work\\ѹ����Ŀ\\Debug\\1.txt", "rb");//��һ���ļ�����Ϊfopenֻ�ܽ���C��ʽ�ַ���������Ҫת��C��ʽ��
	if (nullptr == fIn)
	{
		assert(false);
		return;
	}
	getchar();
	unsigned char* buff = new unsigned char[1024];//����������ļ������������ݡ�
	int readsize = 0;
	while (true)//���һ�ζ����꣬����ѭ�����
	{
		readsize=fread(buff, 1, 1024, fIn);//һ���ַ�ռһ���ֽڣ�һ�ζ�1024����Ҳ����1K������
		if (readsize == 0)//���readsize==0˵��������
			break;
		for (int i = 0; i < readsize; i++)//ͳ���ļ��ж��������ַ������Գ��ֵĴ�����
			_file[buff[i]]._count++;//��Ϊ_file����256��Ԫ�أ����Կ��Կ���ASKII�룬
			                        //������Ҫͳ��buff���ַ����ֵĴ�����ֻ��Ҫ��buff������ַ���Ϊ_file������±꣬�ҵ���Ӧ��
			                       //�ַ��ṹ�壬ʹ���������++���ɡ�
	}
	//2.���ַ��ĳ��ִ���ΪȨֵ������������

	Huffmantree<Char> t;
	Char c;
	c._count = 0;
	t.CreatHuffmantree(_file,c);//�˴������ǽṹ�����飬��Ҫ����Huffman��Ҫ���ع��ڽṹ��ļӷ��Լ����ںš�

	//3.��ȡÿ���ַ��ı���

	filecompressHuff::GetCode(t.GetROOT());

	//4.�û�ȡ�����ַ��������¸�дԭ�ļ�


	delete[] buff;
	fclose(fIn);
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
		node* cur = root;
		node* parent = cur->_parent;//parentΪ��ʱcur�ĸ��ڵ㡣
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