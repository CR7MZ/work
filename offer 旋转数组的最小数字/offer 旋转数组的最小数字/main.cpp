//题目：https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba?f=discussion
#include<iostream>
#include<vector>
using namespace std;
//因为旋转之后的数组可以划分为两个有序的子序列，且前面的子数组的大小一定都大于后面子数组的大小。此时我们可以发现最小的数字就是两个子数组的分界线
//因为本题的数组相当于排序的，所以我们可以先用二分查找来找到最小的数字。
//1.用两个指针left，right分别指向数组的第一个元素，和最后一个元素。
//2.找到中间的元素，若中间的元素大于第一个元素，说明中间的元素位于前面的递增子数组，此时最小元素一定位于中间元素的后面。我们可以让left指向中间的元素。
//若中间元素小于第一个元素，说明中间的元素位于后面的递增子数组，此时最小元素一定位于中间元素的前面。我们可以让right指向中间的元素。

//按照上面的思路，left永远指向前面子数组中的元素，right永远指向后面子数组中的元素。最终left会指在前面数组最后一个元素，right会指在后面数组第一个元素。
//也就是他们两个相邻，此时right恰好是最小的元素。所以如果right-1等于left，说明right指向最小的元素。
//但是题目指明 数组可以有重复的数字，也就是说数字可以为{1，0,1,1,1,1}。所以我们无判断中间元素是前面子数组或是后面子数组，从而无法找出结果，所以只能暴力寻找最小值。
//这样题目才算全部完成。
int minNumberInRotateArray(vector<int> rotateArray) {
	int size = rotateArray.size();
	int left = 0, right = size - 1;
	int mid = 0;
	while (rotateArray[left] >= rotateArray[right])//确保可以旋转
	{
		if (left == right - 1)//说明相邻，得出最小值的下标
		{
			mid = right;
			break;
		}

		mid = left + (right - left) / 2;
		if (rotateArray[mid] == rotateArray[left] && rotateArray[mid] == rotateArray[right])//如果三者相同，无法确认中间元素是前面子数组或是后面子数组，用暴力查找
			return Func(rotateArray, left, right);
		if (rotateArray[mid] >= rotateArray[left])//中间元素位于前面递增子数组，此时最小元素在中间元素后面。
			left = mid;
		else                                      //中间元素位于后面递增子数组，此时最小元素在中间元素前面。
			right = mid;
	}
	return rotateArray[mid];
}
int Func(vector<int>& v, int left, int right)
{
	int res = v[left];
	for (int i = left + 1; i<right; i++)
	{
		if (v[i]<res)
			res = v[i];
	}
	return res;
}
int main()
{

}