//题目：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe?f=discussion
#include<iostream>
#include<vector>

//思路：双指针计数
//左右两边有两个指针，一个低指针left，一个高指针right。相当于两个指针形成了一个窗口。将两个指针之间的内容相加，若大于sum
//说明数大了，减小和的方法就是left++。如果小于sum，说明数笑了，增大和的方法就是right++。
//若相等将这段连续的数放入tmp中，最后放入res，之后如果right继续++数只会越来越大于sum，所以应该left--判断下一组。
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
				std::vector<int> tmp;//保存每一组数据

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