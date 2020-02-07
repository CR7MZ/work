//题目：https://www.nowcoder.com/questionTerminal/459bd355da1549fa8a49e350bf3df484?f=discussion
#include<iostream>
#include<vector>
using namespace std;

//遇到这一个题，我们首先可以这样考虑，设置一个sum和result，sum是用来每次加新的元素，
//result是最后得出最大的子数组和。我们可以每次给sum中添加新的元素，从第一个开始向后，
//如果遇到和比result大的时候，就把sum的值赋给result，小于的话则继续向后寻找，
//当然我们也考虑到了如果数组中的数字为负数的时候，每次加新的数字之后，
//会判断sum是否为正，如果不为正数，就将sum置为0，那么在下一次加的时候，前面的负数不会考虑，
//因为越加会越小，但是我们还是会比较result跟sum的大小，因为即便为负数，也会存在大小问题，
//所以这样的话我们可以比较后面的子数组与前面的大小比较，最后找到最大值。


int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i<n; i++)
	{
		cin >> v[i];
	}
	int max = v[0];
	int sum = 0;
	for (int i = 0; i<v.size(); i++)
	{
		sum += v[i];
		if (sum>max)//此语句一定要在sum<0语句前，否则会出现数组中全是负数的报错。
			//{-5，-1，-6，-9，-3}
			//如果是全负数的数组，此语句放在sum<0的前面，就会造成最终输出为0，因为一直在执行sum<0语句的内容。输出就不是负数中最大的了。
		{
			max = sum;
		}
		if (sum<0)
		{
			sum = 0;
		}
	}
	cout << max << endl;
	return 0;
}