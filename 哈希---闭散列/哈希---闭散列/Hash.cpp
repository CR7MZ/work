#include<iostream>
#include<vector>
#include<string>
#include"common.h"
using namespace std;

enum status { EXI, EMP, DEL };//��¼��ʱ��ϣ��ַ�����ݴ���ʲô״̬�����ڡ��ա�ɾ��

template<class T>
struct elem   //��Ϊ��Ҫ��¼ÿ�����ݵ�״̬
{
	elem(const T& data=T())
		:_val(data)
		, _sta(EMP)
	{}
	T _val;
	status _sta;
};

//�º������� ������һ����Ķ�����԰��պ����ķ�ʽ���е���
 template<class T>//��TΪ����
 class DFdef
 {
 public:
	 size_t operator()(const T& data)
	 {
		 return data;
	 }
 };

 //��TΪstring��Ķ���
 class DFstr
 {
 public:
	 size_t operator()(const string& str)
	 {
		 return Func(str.c_str());
	 }
 private:
	 size_t Func(const char* str)//���������ҵĺ��������ַ���תΪ����
	 {
		 register size_t hash = 0;
		 while (size_t ch = (size_t)*str++)
		 {
			 hash = hash * 131 + ch;
		 }
		 return hash;
	 }
 };
 //��ʱ��ϣ��Ϳ���ʵ�ֶ�string���͡��Լ����εĴ洢��֮�����µ����ͳ��֣���д�º�����

//�Լ��涨����ϣ���в������ظ�������
//T:Ԫ������
//DF���º��������Խ���ͬ���͵����ݱ�Ϊ�������ݣ��ù�ϣ����ȥ���㡣Ĭ��ʹ��DFdef�ķº������÷º������Դ洢�������͵�Ԫ�ء�
//is��������������̽�⣬���Ƕ���̽�⣬��ʼ��Ϊtrue
 template<class T, class DF = DFdef<T>, bool is = true>
class Hash
{
public:
	Hash(size_t cap=10)//��ʼ����ϣ�������
		:_size(0)
		, _total(0)
	{
		_table.resize(GetNextPrime(cap));
	}

	bool insert(const T& data)
	{
		int hashaddr = hashFunc(data);//1.ͨ����ϣ�����ó���ϣ��ַ

		size_t i = 0;
		//2.Ѱ�ҿ�λ��
		while (_table[hashaddr]._sta != EMP)
		{
			//����˹�ϣ��ַ״̬Ϊ���ڣ��Ҵ˴����ݺ�����Ҫ�����������ͬ���򲻲��롣���Լ��涨��
			if (_table[hashaddr]._sta == EXI&&_table[hashaddr]._val == data)
				return false;

			if (is == true)
			{
				//��������̽�⣬�����ҿ�λ��
				hashaddr++;
				//˵����ַ�Ѿ�Խ���ˣ�����ϣ��ַ��Ϊ0����ͷ��ʼ�ҡ�
				if (hashaddr == _table.capacity())
					hashaddr = 0;
			}
			else
			{
				//����̽��
				i++;
				hashaddr = hashaddr + 2 * i + 1;

				//����̽���ַԽ��
				hashaddr %= _table.capacity();
			}		
		}
		_table[hashaddr]._val = data;
		_table[hashaddr]._sta = EXI;
		++_size;
		++_total;
		return true;
	}

	int find(const T& data)
	{
		int HashAddr = hashFunc(data);
		size_t i = 0;
		while (_table[HashAddr]._sta != EMP)
		{
			if (_table[HashAddr]._sta == EXI&&_table[HashAddr]._val == data)
			{
				return HashAddr;
			}

			if (is == true)//����ģ�崫���bool���͵�ֵ�����ж������Ի��Ƕ��Ρ�
			{
				//��������̽�⣬�����ҿ�λ��
				HashAddr++;
				//˵����ַ�Ѿ�Խ���ˣ�����ϣ��ַ��Ϊ0����ͷ��ʼ�ҡ�
				if (HashAddr == _table.capacity())
					HashAddr = 0;
			}
			else
			{
				//����̽��
				i++;
				HashAddr = HashAddr + 2 * i + 1;

				//����̽���ַԽ��
				HashAddr %= _table.capacity();
			}
		}
		return -1;
	}
	
	bool Erase(const T& data)
	{
		int pos = find(data);
		if (pos!=-1)
		{
			//��Ҫɾ���Ĺ�ϣ��ַ�ϵ�����״̬��Ϊɾ��״̬����ע�������ɾ������������ɾ����ֻ�ǽ�״̬����ЧԪ�ظı䣬�����˵��ɾ����ʵ�ʻ���ռ��ϣ���ڴ�ģ�
			_table[pos]._sta = DEL;
			--_size;
			return true;
		}
		return false;
	}
	size_t Size_()const
	{
		return _size;
	}

	void Swap(Hash<T, DF, is> ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}
	//���������Ӵ���0.7��ʱ���ϣ���������
	//������ݣ�
	//1.���ܰ�vector�ĵײ����ݡ�
	//2.������2���ķ�ʽ�������ݡ�
	//3.��Ϊ����֪����ϣ�������%һ����������������Ҫ��֤���ݺ�������СΪ������
	//4.����GetNextPrime�����������ж�����Ӧ������Ϊ����������
private:
	void Checkcap()
	{
		if (_total * 10 / _table.capacity() >= 7)
		{
			Hash<T, DF, is> NewHash(GetNextPrime(_table.capacity()));

			for (auto e : _table)
			{
				if (e._sta==EXI)
					NewHash.insert(e)
			}
			Swap(NewHash);
		}
	}
	size_t hashFunc(const T& data)//��ϣ��������������������������%��ϣ�������
	{
		//DF df;//��Ϊ���������˷º�����������Ҫ����һ������
		////�о����ֳ������������������%һ��������
		//return df(data) % 10;//��data����df�º����������data֮ǰ������תΪ���Ρ���df�����Ƕ��󣬲��Ǻ���

		//һ�������ôд
		return DF()(data) % _table.capacity();//DF()˵��������һ���������� 
	}
private:
	vector<elem<T>> _table;
	size_t _size;//��ϣ���д洢����ЧԪ�أ�ֻ��������״̬��Ԫ�أ�������ɾ��״̬�ġ���
	size_t _total;//��ϣ�����Ѿ��洢�ĸ�������������Ԫ�أ�
};

int main()
{
	return  0;
}