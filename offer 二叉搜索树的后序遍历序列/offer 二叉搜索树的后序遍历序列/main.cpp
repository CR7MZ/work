//��Ŀ��https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd?f=discussion
#include<iostream>
#include<vector>
//�ݹ飺
//����Ŀ�õ�����Ϊ�Ǻ�������������������һ��Ԫ��һ�������ĸ�root������Ϊ�Ƕ������������������������е�ֵС��root�����������е�ֵ
//����root
//1.���ҵ�root����¼�ϡ�
//2.���������ҵ���һ������root��ֵ���±꣬ͬʱ��֮ǰ������ֵ��������left�С����������������������ұ�����������
//3.������������ͬʱ����������������right�С�����С��root�Ե�ֵ��ֱ�ӷ���false��
//4.�ֱ��ж����������ǲ��Ƕ�����������ѭ��1��2��3���衣
bool VerifySquenceOfBST(std::vector<int> sequence)
{
	if (sequence.empty())//�������ж��������Ƿ�Ϊ�ա�
		return false;
	std::vector<int> left, right;
	int size = sequence.size();
	int i = 0;
	int root = sequence[size - 1];
	for (; i < size - 1; i++)
	{
		if (sequence[i] < root)
			left.push_back(sequence[i]);
		else
			break;
	}
	for (int j = i; j < size - 1; j++)
	{
		if (sequence[j] > root)
			right.push_back(sequence[j]);
		else
			return false;
	}	
	bool le = true, ri = true; //��Ϊ�����в�Ϊ�գ������������Ϊ��Ҳ�Ƕ��������������ý��еݹ顣���Դ���������le��������ri��ʼ��Ϊtrue��
	if (!left.empty())
		le = VerifySquenceOfBST(left);
	if (!right.empty())
		ri = VerifySquenceOfBST(right);
	return le&&ri;
}

//�ǵݹ飺
bool VerifySquenceOfBST2(std::vector<int> sequence)
{
	int size = sequence.size();
	if (0 == size) return false;

	int i = 0;
	while (--size){
		while (sequence[i++] < sequence[size]);
		while (sequence[i++] > sequence[size]);

		if (i < size) return false;

		i = 0;
	}

	return true;
}