//��Ŀ��https://www.nowcoder.com/questionTerminal/623a5ac0ea5b4e5f95552655361ae0a8?f=discussion
#include<iostream>
#include<vector>
//����һ�����bool���͵�����v����ʼ��Ϊfalse
//��numbers�е�������v���±꣬numbers�е��������ˣ��ͽ���Ӧλ����Ϊtrue��
//����V���ҵ�ֵΪtrue��λ�ã���λ�÷��أ���Ϊ��һ���ظ����ֵ����֡�
bool duplicate(int numbers[], int length, int* duplication) {
	std::vector<bool> v(length, false);
	for (int i = 0; i<length; i++)
	{
		if (v[numbers[i]] == true)
		{
			*duplication = numbers[i];
			return true;
		}
		v[numbers[i]] = true;
	}
	return false;
}