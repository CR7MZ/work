//��Ŀ��https://www.nowcoder.com/questionTerminal/e02fdb54d7524710a7d664d082bb7811?f=discussion
#include<iostream>
#include<vector>
//˼·�������ķ�����
//1.��Ϊ�������ԣ�������ȫ�����õ�����ֻ����һ�Σ�����A��B���������Ľ��res��
//2.��Ϊ����ǣ���ͬΪ0������Ϊ1������res����Ϊ1�ı���λ������AB����������ı���λ���������Ҫ��res��һ��Ϊ1�ı���λ��λ��index��
//3.��index��ԭ�����Ϊ���飬�����׼�ǵ�indexΪ�Ƿ�Ϊ1.
//4.��ˣ�������ͬ����AB�ͷֿ��ˣ����������ֱ���򣬵õ�����ֻ����һ�ε�����

int Findfir1(int tmp)//�ҵ�������res�е�һ1��λ��
{
	int i = 0;
	for (; i<32; i++)
	{
		if ((tmp & 1) == 1)
			return i;
		tmp >>= 1;
	}
	return -1;
}
bool Func(int x, int index)//�����ж�indexλ�Ƿ�Ϊ1
{
	return (((x >> index) & 1) == 1);
}
void FindNumsAppearOnce(std::vector<int> data, int* num1, int *num2) {
	if (data.size() == 2)
	{
		*num1 = data[0];
		*num2 = data[1];
	}
	else
	{
		*num1 = 0;
		*num2 = 0;
		int res = 0;
		for (size_t i = 0; i<data.size(); i++)
		{
			res ^= data[i];
		}
		int index = Findfir1(res);
		for (size_t i = 0; i<data.size(); i++)
		{
			if (Func(data[i], index))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
	}
}
