//��Ŀ��https://www.nowcoder.com/questionTerminal/762836f4d43d43ca9deb273b3de8e1f4?f=discussion
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//����˼·��
//��Ϊ˳��ֻ�������ţ�����0�����ܷ�����β
//�������Ǽ�ס������һ����������һ����С�������������ֻ��>=5����false��
bool IsContinuous(vector<int> numbers, int)
{
	if (numbers.size() != 5)
		return false;
	int min = 14;
	int max = -1;
	int flag = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		int num = numbers[i];
		if (num == 0)
			continue;
		if (((flag >> num) & 1) == 1)
			return false;
		flag |= (1 << num);
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		if (max - min >= 5)
			return false;
	}
	return true;
}



//����˼·��
//��������0�������������ַŵ�������res�У����������飬����res����cur��ͳ��res��ÿ������������֮����˼�����
//���curΪ-1˵���������ظ������ˣ�����false��������count����cur�������������count��0�ĸ�����Ƚϣ�0�������򷵻�true��
bool IsContinuous(vector<int> numbers) {
	if (numbers.size() != 5)
		return false;
	vector<int> res;
	int tmp = 0;
	for (auto e : numbers)
	{
		if (e != 0)
			res.push_back(e);
		else if (e == 0)
			tmp++;
	}
	int count = 0;
	sort(res.begin(), res.end());
	for (int i = 0; i<res.size() - 1; i++)
	{
		int cur = res[i + 1] - res[i] - 1;
		if (cur == -1)
			return false;
		count += cur;
	}
	if (count>tmp)
		return false;
	return true;
}