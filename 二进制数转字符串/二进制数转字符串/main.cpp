#include <iostream>
#include <string>
using namespace std;
//题目：https://leetcode-cn.com/problems/bianry-number-to-string-lcci/

//解析：小数的十进制转换成二进制，方法是乘2，如果乘2后变为整数，那么字符串0.后面追加1，并且-1
//      如果乘2后变为小数，那么字符串0.后面追加0，并且-1。直到当前数字为0。并且需要对追加的数字个数
//      进行计数，若大于32则说明不在32位内，返回ERROR
class solution {
public:
	string printBin(double num) {
		string res = "0.";
		int count = 2;
		num *= 2;
		while (num){
			if (count > 32){
				return "ERROR";
			}
			if (num >= 1){
				count++;
				res += '1';
				num -= 1;
			}
			else if (num < 1){
				count++;
				res += '0';
			}
			num *= 2;
		}
		return res;
	}
};