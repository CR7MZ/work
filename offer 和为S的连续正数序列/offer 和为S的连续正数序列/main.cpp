//��Ŀ��https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe?f=discussion
#include<iostream>
#include<vector>

//˼·��˫ָ�����
//��������������ָ�룬һ����ָ��left��һ����ָ��right���൱������ָ���γ���һ�����ڡ�������ָ��֮���������ӣ�������sum
//˵�������ˣ���С�͵ķ�������left++�����С��sum��˵����Ц�ˣ�����͵ķ�������right++��
//����Ƚ����������������tmp�У�������res��֮�����right����++��ֻ��Խ��Խ����sum������Ӧ��left--�ж���һ�顣
class solution
{
	std::vector<std::vector<int> > FindContinuousSequence(int sum)
	{
		std::vector<std::vector<int>> res;
		int left = 1;
		int right = 2;

		while (left<right)
		{
			int cur = ((left + right)*(right - left + 1)) >> 1;
			if (cur == sum)
			{
				std::vector<int> tmp;//����ÿһ������

				for (int i = left; i <= right; i++)
					tmp.push_back(i);

				res.push_back(tmp);
				left++;
			}
			else if (cur>sum)
				left++;
			else
				right++;
		}
		return res;
	}
};