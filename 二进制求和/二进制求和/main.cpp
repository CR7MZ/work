//��Ŀ��https://leetcode-cn.com/problems/add-binary/submissions/
#include<iostream>
//�Ƚ�a��b�ַ�ÿ��λ�������,ȫ��������ж��Ƿ��н�λ�������ʱֵ���ڵ���2��˵���н�λ������������¼��λ��carry��Ϊ1����֮��Ϊ0��
//�����ʱcarryΪ1��˵����λ�õ���һ��λ���н�λ�������ȼ���1���ٽ��к����ж��Ƿ������ǰ��λ��
std::string addBinary(std::string a, std::string b) {
	int na = a.size();
	int nb = b.size();
	if (na<nb)//���ַ���a������Ӻ����
	{
		a.swap(b);
	}
	int carry = 0;
	int pos = a.size() - 1;
	for (int i = b.size() - 1; i >= 0; i--)
	{
		a[pos] += b[i] - '0';
		pos--;
	}
	pos = a.size() - 1;
	while (pos >= 0)
	{
		if (carry == 1)//˵����λ�õ�ǰһ��λ�ý�λ�ˣ���λ�õ�����Ҫ��1
			a[pos] += 1;
		if (a[pos] >= '2')//˵����λ�����ִ���2����Ҫ��λ����carryΪ1������һ��λ��ʹ��
		{
			carry = 1;
			a[pos] = (a[pos] - '0') % 2 + '0';
		}
		else
			carry = 0;
		pos--;
	}
	if (carry == 1)//˵�����λ����һλ�����ַ���ǰ������1���ɡ�
		a.insert(0, "1");
	return a;
}
int main()
{
	std::string s("101");
	std::string s2("1");
	addBinary(s, s2);
	return  0;
}