//��Ŀ��https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1?f=discussion
#include<iostream>
//�ݹ������ӣ��жϽ���������Ϊre&&��Ҳ����˵��reΪ0�ˣ��򲻽���&&�����������
//�������������·�����ʡ�
int Sum_Solution(int n) {
	int re = n;
	re && (re += Sum_Solution(n - 1));
	return re;
}