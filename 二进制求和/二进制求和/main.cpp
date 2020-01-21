//题目：https://leetcode-cn.com/problems/add-binary/submissions/
#include<iostream>
//先将a、b字符每个位相加起来,全部加完后，判断是否有进位，如果此时值大于等于2，说明有进位，定义用来记录进位的carry置为1，反之置为0。
//如果此时carry为1，说明此位置的上一个位置有进位，所以先加上1，再进行后面判断是否继续向前进位。
std::string addBinary(std::string a, std::string b) {
	int na = a.size();
	int nb = b.size();
	if (na<nb)//用字符串a来保存加后的数
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
		if (carry == 1)//说明此位置的前一个位置进位了，此位置的数需要加1
			a[pos] += 1;
		if (a[pos] >= '2')//说明此位置数字大于2，需要进位。将carry为1，供下一个位置使用
		{
			carry = 1;
			a[pos] = (a[pos] - '0') % 2 + '0';
		}
		else
			carry = 0;
		pos--;
	}
	if (carry == 1)//说明最高位进了一位，在字符串前面插入个1即可。
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