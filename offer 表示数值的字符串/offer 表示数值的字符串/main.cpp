//��Ŀ��https://www.nowcoder.com/questionTerminal/6f8c901d091949a5837e24bb82a731f2?f=discussion
#include<iostream>
//˼·��
//���������
bool isNumeric(char* string)
{
	//��� e/E��.��+/-�Ƿ����
	bool Point = false, Signal = false, HasE = false;
	for (size_t i = 0; i<strlen(string); i++)
	{
		if (string[i] == 'E' || string[i] == 'e')
		{
			if (i == strlen(string) - 1) return false;//����E�����������Ԫ��
			if (HasE) return false;//Eֻ�ܳ���һ��
			HasE = true;
		}
		else if (string[i] == '-' || string[i] == '+')
		{
			//�ڶ��γ��ַ��ţ�������E����
			if (Signal&&string[i - 1] != 'e'&&string[i - 1] != 'E') return false;
			//��һ�γ��ַ��ţ��Ҳ���ͷ��Ҳ������E����
			if (!Signal&&i>0 && string[i - 1] != 'e'&&string[i - 1] != 'E') return false;
			Signal = true;
		}
		else if (string[i] == '.')
		{
			//ֻ����һ��.��E���治����.
			if (HasE || Point) return false;
			Point = true;
		}
		else if (string[i]<'0' || string[i]>'9')
		{
			//ֻ���������ַ�
			return false;
		}
	}
	return true;
}