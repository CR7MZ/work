//��Ŀ��
#include <iostream>
#include <queue>

//˼·��
//����һ�����������ַ����м������ٶ���һ�����У�����һ�γ��ֵ��ַ����룬���ͨ����ȡ����ͷԪ����ͨ�������ж��ǲ���ֻ����һ�ε��ַ�
//���ǣ�����ַ����ǵ�һ�����ظ����ֵ��ַ���
int v[256];
std::queue<char> tmp;

void Insert(char ch)
{
	v[ch]++;
	if (v[ch] == 1)
		tmp.push(ch);
}
char FirstAppearingOnce()
{
	while (!tmp.empty() && v[tmp.front()]>1)
		tmp.pop();
	if (tmp.empty()) return '#';
	return tmp.front();
}
void Func()
{
	memset(v, 0, sizeof(v));//�����鸳ֵΪ0
}

