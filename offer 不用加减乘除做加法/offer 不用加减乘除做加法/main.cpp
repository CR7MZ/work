//��Ŀ��https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215?f=discussion
#include<iostream>
//˼·��
//��λ����
//����൱�����ӷ�
//��λ�벢����һλ�൱�ڲ鿴���Ƿ��н�λ
//��num==0˵��û�н�λ�ˣ���num1��Ϊ�����
int Add(int num1, int num2)
{
	while (num2 != 0)
	{
		int sum = num1^num2;
		int car = (num1&num2) << 1;
		num1 = sum;
		num2 = car;
	}
	return num1;
}