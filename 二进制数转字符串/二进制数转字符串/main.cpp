#include <iostream>
#include <string>
using namespace std;
//��Ŀ��https://leetcode-cn.com/problems/bianry-number-to-string-lcci/

//������С����ʮ����ת���ɶ����ƣ������ǳ�2�������2���Ϊ��������ô�ַ���0.����׷��1������-1
//      �����2���ΪС������ô�ַ���0.����׷��0������-1��ֱ����ǰ����Ϊ0��������Ҫ��׷�ӵ����ָ���
//      ���м�����������32��˵������32λ�ڣ�����ERROR
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