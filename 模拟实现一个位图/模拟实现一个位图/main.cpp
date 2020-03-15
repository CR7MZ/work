#include "bitemap.hpp"
#include <iostream>
int main()
{
	My::bitemap<50> bit;
	bit.set(1);
	std::cout<<bit.count();
	bit.test(1);
	return 0;
}