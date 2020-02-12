#include<iostream>
#include<vector>
#include<string>
#include"common.h"
using namespace std;

enum status { EXI, EMP, DEL };//记录此时哈希地址的数据处于什么状态：存在、空、删除

template<class T>
struct elem   //因为需要记录每个数据的状态
{
	elem(const T& data=T())
		:_val(data)
		, _sta(EMP)
	{}
	T _val;
	status _sta;
};

//仿函数对象 就是让一个类的对象可以按照函数的方式进行调用
 template<class T>//若T为整形
 class DFdef
 {
 public:
	 size_t operator()(const T& data)
	 {
		 return data;
	 }
 };

 //若T为string类的对象
 class DFstr
 {
 public:
	 size_t operator()(const string& str)
	 {
		 return Func(str.c_str());
	 }
 private:
	 size_t Func(const char* str)//利用网上找的函数，将字符串转为数字
	 {
		 register size_t hash = 0;
		 while (size_t ch = (size_t)*str++)
		 {
			 hash = hash * 131 + ch;
		 }
		 return hash;
	 }
 };
 //此时哈希表就可以实现对string类型、以及整形的存储。之后有新的类型出现，再写仿函数。

//自己规定：哈希表中不能有重复的数据
//T:元素类型
//DF：仿函数，可以将不同类型的数据变为整形数据，让哈希函数去计算。默认使用DFdef的仿函数，让仿函数可以存储任意类型的元素。
//is：来区别用线性探测，还是二次探测，初始化为true
 template<class T, class DF = DFdef<T>, bool is = true>
class Hash
{
public:
	Hash(size_t cap=10)//初始化哈希表的容量
		:_size(0)
		, _total(0)
	{
		_table.resize(GetNextPrime(cap));
	}

	bool insert(const T& data)
	{
		int hashaddr = hashFunc(data);//1.通过哈希函数得出哈希地址

		size_t i = 0;
		//2.寻找空位置
		while (_table[hashaddr]._sta != EMP)
		{
			//如果此哈希地址状态为存在，且此处数据和我们要插入的数据相同，则不插入。（自己规定）
			if (_table[hashaddr]._sta == EXI&&_table[hashaddr]._val == data)
				return false;

			if (is == true)
			{
				//进行线性探测，挨个找空位置
				hashaddr++;
				//说明地址已经越界了，将哈希地址置为0，从头开始找。
				if (hashaddr == _table.capacity())
					hashaddr = 0;
			}
			else
			{
				//二次探测
				i++;
				hashaddr = hashaddr + 2 * i + 1;

				//二次探测地址越界
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

			if (is == true)//根据模板传入的bool类型的值，来判断用线性还是二次。
			{
				//进行线性探测，挨个找空位置
				HashAddr++;
				//说明地址已经越界了，将哈希地址置为0，从头开始找。
				if (HashAddr == _table.capacity())
					HashAddr = 0;
			}
			else
			{
				//二次探测
				i++;
				HashAddr = HashAddr + 2 * i + 1;

				//二次探测地址越界
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
			//将要删除的哈希地址上的数的状态置为删除状态。（注意这里的删除不是真正的删除，只是将状态和有效元素改变，给外界说明删除，实际还是占哈希表内存的）
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
	//当负载因子带到0.7的时候哈希表进行扩容
	//如何扩容：
	//1.不能按vector的底层扩容。
	//2.尽量按2倍的方式进行扩容。
	//3.因为我们知道哈希函数最好%一个素数，所以我们要保证扩容后容量大小为素数。
	//4.调用GetNextPrime（）函数来判断我们应该扩容为多大的容量。
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
	size_t hashFunc(const T& data)//哈希函数（除留余数法）：让数据%哈希表的容量
	{
		//DF df;//因为我们运用了仿函数，所以需要建立一个对象
		////研究发现除留余数法，最好让其%一个素数。
		//return df(data) % 10;//将data传入df仿函数对象里，将data之前的类型转为整形。但df本质是对象，不是函数

		//一般情况这么写
		return DF()(data) % _table.capacity();//DF()说明创建了一个无名对象， 
	}
private:
	vector<elem<T>> _table;
	size_t _size;//哈希表中存储的有效元素（只包括存在状态的元素，不包括删除状态的。）
	size_t _total;//哈希表中已经存储的个数（包含所有元素）
};

int main()
{
	return  0;
}