//��Ŀ��https://www.nowcoder.com/questionTerminal/72a5a919508a4251859fb2cfb987a0e6?f=discussion
#include<iostream>
using namespace std;
//�ݹ飺
//˼·��ͨ���ҹ��ɷ��֣�
//nΪ1ʱ,��һ�ַ�����
//nΪ2ʱ�������ַ�����
//nΪ3ʱ�������ַ�����
//nΪ4ʱ�������ַ�����
//�������ǿ��Կ�������һ��쳲��������У�nΪnʱ����f(n-1)+f(n-2)�з�����
class solution
{
public:
//��һ��˼·��
//ͬ����쳲��������С�
//��Ϊ��n����Σ����Ծ���f(n)�ַ�����������ȫ��Ϊ���ֿ��ܡ�
//�����һ�������ŷŵģ�˵����ʣn-1����Σ�����f(n-1)�ַ�����
//�����һ���Ǻ��ŷŵģ���������ľ���ֻ�ܺ���ţ�����f(n-2)�ַ���
	int rectCover(int number)//numberΪn
	{
		if (number <= 0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		//�ݹ飬ʱ������
		return rectCover(number - 1) + rectCover(number - 2);

		//Ҳ���õ�����ʱ���ܿ�Щ��
		int first = 1, sec = 2, thir = 0;
		for (int i = 3; i < number; i++)
		{
			thir = first + sec;
			first = sec;
			sec = thir;
		}
		return thir;
	}
};