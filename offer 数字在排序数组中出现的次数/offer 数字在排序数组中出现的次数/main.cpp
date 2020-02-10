//题目：https://www.nowcoder.com/questionTerminal/70610bf967994b22bb1c26f9ae901fa2?f=discussion
#include<iostream>
#include<vector>
//思路：
//1.因为是排序的数组，所以直接用二分查找，分别找到最靠左的k和最靠右的k的下标。最后求出长度。
int Getstart(std::vector<int> v, int k, int begin, int end)
{
	if (begin > end)
		return -1;
	int mid = (begin + end) >> 1;
	if (v[mid] > k)
		return Getstart(v, k, begin, mid - 1);
	else if (v[mid] < k)
		return Getstart(v, k, mid + 1, end);
	else if (mid - 1 >= 0 && v[mid - 1] == k)//如果此时v[mid]==k，但是v[mid-1]也==k（前提mid>=1）,此时不是最左端的k。继续查找。
		return Getstart(v, k, begin, mid - 1);
	else
		return mid;
}
//非递归,用循环的二分查找
//int Getstart(std::vector<int> v, int k, int begin, int end)
//{
//	int len = v.size();
//	int mid = (begin + end) >> 1;
//	while (begin <= end)
//	{
//		if (v[mid]>k)
//			end = mid - 1;
//		else if (v[mid]<k)
//			begin = mid + 1;
//		else if (mid - 1 >= 0 && v[mid - 1] == k)
//			end = mid - 1;
//		else
//			return mid;
//		mid = (begin + end) >> 1;
//	}
//	return -1;
//}

int Getend(std::vector<int> v, int k, int begin, int end)
{
	if (begin > end)
		return -1;
	size_t mid = (begin + end) >> 1;
	if (v[mid] > k)
		return Getend(v, k, begin, mid - 1);
	else if (v[mid] < k)
		return Getend(v, k, mid + 1, end);
	else if (mid + 1<v.size() && v[mid + 1] == k)
		return Getend(v, k, mid + 1, end);
	else
		return mid;
}

int GetNumberOfK(std::vector<int> data, int k)
{
	int len = data.size();
	if (len == 0)
		return 0;
	int left = Getstart(data, k, 0, len - 1);//得到最左边k的下标
	int right = Getend(data, k, 0, len - 1);//得到最右边k的下标
	if (left != -1 && right != -1)
		return right - left + 1;
	return 0;
}