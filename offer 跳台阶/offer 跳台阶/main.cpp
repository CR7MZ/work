//��Ŀ��https://www.nowcoder.com/questionTerminal/8c82a5b80378478f9484d87d1c5f12a4?f=discussion
#include<iostream>
//1.����
//˼·:ͨ��ǰ���ҹ��ɷ��֣����ֻ��һ��̨��f(1),��ֻ��һ����������ֻ������̨��f(2)����������������f(3)�����֣�f(4)��5�С�
//���ǿ��Է���f(n)=f(n-1)+f(n-2)������Ϊʲô���������Ĺ����أ���Ϊ����һ��ֻ����һ����������̨�ס����Լ�������5��̨�ף�
//���ǿ��Դӵ�4��̨����һ������5��̨�ף������ж����ַ���������4��̨�ף����ж����ַ�������5��̨�ס�
//Ҳ���Դӵ�3��̨������������5��̨�ס������ж����ַ���������3��̨�ף����ж����ַ�������5��̨�ס�
//���Ծ���f(5)=f(4)+f(3)
class solution
{
public:
	int jumpFloor(int number) {
		if (number<0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		int fir = 1, sec = 2, thir = 0;
		for (int i = 3; i <= number; i++)
		{
			thir = fir + sec;
			fir = sec;
			sec = thir;
		}
		return thir;
	}

//2.�ݹ�
//����˵�������������������һ������1��̨�ף���ôʣ��n-1��̨�ף�Ҳ����f(n-1)��������
//�����һ������2��̨�ף���ôʣ��n-2��̨�ף�Ҳ����f(n-1)��������
//���Եó���������f(n)=f(n-1)+f(n-2)
//���Ǻ�����ֱ��f(1)=1,f(2)=2��
//���տ��Է��֣��ó�������һ��쳲��������С�
	int jumpFloor(int number) {
		if (number<0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		return jumpFloor(number-1) + jumpFloor(number - 2);
	}
};
int main()
{
	solution s;
	std::cout<<s.jumpFloor(4)<<std::endl;
	system("pause");
	return 0;
}