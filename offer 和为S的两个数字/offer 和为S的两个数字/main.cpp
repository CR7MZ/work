//��Ŀ��https://www.nowcoder.com/questionTerminal/390da4f7a00f44bea7c2f3d19491311b?f=discussion
#include<iostream>
#include<vector>

//˼·��
//1.��Ϊ�ǵ����ġ�
//2.��������ָ��ͷβ��ָ�롣
//3.��array[i] + array[j] == sum���õ�����������Ϊ��Զ�˵��������ɼ���С��
//4.��array[i] + array[j] <  sum��˵��С�ˣ��������++��
//5.��array[i] + array[j] >  sum��˵�����ˣ��ұ�����--��
std::vector<int> FindNumbersWithSum(std::vector<int> array, int sum) {
	std::vector<int> res;
	int i = 0;
	int j = array.size() - 1;
	while (i<j)
	{
		if (array[i] + array[j] == sum)
		{
			res.push_back(array[i]);
			res.push_back(array[j]);
			break;
		}
		else if (array[i] + array[j]>sum)
			j--;
		else
			i++;
	}
	return res;
}