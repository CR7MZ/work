//��Ŀ��https://leetcode-cn.com/problems/subsets/submissions/
#include<iostream>
#include<vector>
//�������е�����һ�ΰ������뵽ǰ��õ������е��Ӽ��У����ɵõ�ȫ�����Ӽ���
std::vector<std::vector<int>> subsets(std::vector<int>& nums)
{
	std::vector<std::vector<int>> res;//���淵�ص������Ӽ�

	std::vector<int> tmp;//����֮ǰ���Ӽ������ڽ����ּ��뵽�Ӽ����γ��µ��Ӽ����ٷ���res�С�

	res.push_back(tmp);//�Ȳ���һ�����Ӽ���

	for (int i = 0; i < nums.size(); i++)//ѭ���������и��������֣������γ����Ӽ��Ĳ���
	{
		int num = res.size();//��¼��ʱ�����˶��ٸ�Ԫ�أ�Ҫ���¼����Ԫ�أ�һ�μ��뵽֮ǰ���Ӽ��У��γ��µ��Ӽ�
		for (int j = 0; j < num; j++)
		{
			tmp = res[j];//��֮ǰ���Ӽ����浽tmp ��

			tmp.push_back(nums[i]);//�������ֲ��뵽tmp��

			res.push_back(tmp);//�������Ӽ����Ż��Ӽ������С�

		}
	}
	return res;
}
int main()
{
	std::vector<int> I = { 1, 2, 3 };
	std::vector<std::vector<int>> v;
	v = subsets(I);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			std::cout << v[i][j] << " ";
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}