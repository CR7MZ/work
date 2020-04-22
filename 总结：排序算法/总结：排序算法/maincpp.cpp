#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

//快排：O(NlgN) 不稳定
int _Qsort(vector<int>& v,int begin,int end )//挖坑
{
	int tmp = v[end];
	int left = begin;
	int right = end;
	while (left < right)
	{
		while (left < right&&v[left] <= tmp)
			left++;
		if (left < right)
		{
			v[right] = v[left];
			right--;
		}
		while (left < right&&v[right] >= tmp)
			right--;
		if (left < right)
		{
			v[left] = v[right];
			left++;
		}
	}
	v[left] = tmp;
	return left;
}

int _Qsort(vector<int>& v, int begin, int end,int k)//双指针交换法
{
	int tmp = v[end];
	int left = begin;
	int right = end;
	while (left < right)
	{
		while (left < right&&v[left] <= tmp)
			left++;
		while (left < right&&v[right] >= tmp)
			right--;
		if (left < right)
		{
			swap(v[left], v[right]);
		}
	}
	swap(v[left], v[end]);
	return left;
}

void Qsort1(vector<int>& v,int begin,int end)//递归实现快排
{
	if (begin >= end)
		return;
	int mid = _Qsort(v, begin, end,1);
	Qsort1(v, begin, mid - 1);
	Qsort1(v, mid + 1, end);
}

void Qsort2(vector<int>& v, int begin, int end)//非递归实现快排
{
	stack<int> s;
	s.push(begin);
	s.push(end);
	while (!s.empty())
	{
		end = s.top();
		s.pop();
		begin = s.top();
		s.pop();

		if (begin >= end)
			continue;
		int mid = _Qsort(v, begin, end,1);
		s.push(begin);
		s.push(mid - 1);
		s.push(mid + 1);
		s.push(end);
	}
}

//--------------------------------------------------------------------------------------
//堆排：O(NlgN) 不稳定

void DownJust(vector<int>& v,int parent,int size)
{
	int child = parent * 2 + 1;
	while (child<size)
	{
		if (child + 1 < size && v[child] < v[child + 1])
			child = child + 1;
		if (v[parent] < v[child])
		{
			swap(v[parent], v[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void CreatHeap(vector<int>& v)
{
	int parent = (v.size() - 1 - 1) >> 1;
	for (; parent >= 0; parent--)
		DownJust(v, parent,v.size());
}

void PopHeap(vector<int>& v,int k)
{
	swap(v[0], v[k]);
	DownJust(v, 0, k);
}

void HeapSort(vector<int>& v)
{
	CreatHeap(v);

	
	for (int i = 0; i < v.size(); i++)
	{
		int  tmp = v.size() - 1-i;
		PopHeap(v, tmp);
	}
}

//--------------------------------------------------------------------------------------
//归并排序 O(NlgN) 稳定

void merge(vector<int>& v,int beg,int mid,int end,vector<int>& tmp)
{
	int index = beg;
	int cur1 = beg;
	int cur2 = mid;
	while (cur1 < mid&&cur2 < end)
	{
		if (v[cur1] < v[cur2])
		{
			tmp[index++] = v[cur1++];
		}
		else
		{
			tmp[index++] = v[cur2++];
		}
	}
	while (cur1<mid)
		tmp[index++] = v[cur1++];
	while (cur2<end)
		tmp[index++] = v[cur2++];

	for (int i = beg; i < end; i++)
		v[i] = tmp[i];
}

void _MergeSort(vector<int>& v, int beg, int end, vector<int>& tmp)
{
	if (beg >= end-1)
		return;
	int mid = beg + (end - beg) /2;
	_MergeSort(v, beg, mid, tmp);
	_MergeSort(v, mid, end, tmp);
	merge(v, beg, mid, end, tmp);
}

void MergeSort(vector<int>& v)
{
	if (v.size() <= 1)
		return;
	vector<int> tmp(v.size(), 0);
	_MergeSort(v, 0, v.size(), tmp);
}

//--------------------------------------------------------------------------------------
//冒泡排序：O(N^2) 稳定
void BubbleSort(vector<int>& v)
{
	if (v.size() <= 1)
		return;
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j]>v[j+1])
				swap(v[j], v[j + 1]);
		}
	}
}

//--------------------------------------------------------------------------------------
//选择排序：O(N^2) 不稳定
void SelectSort(vector<int>& v)
{
	if (v.size() <= 1)
		return;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i+1; j < v.size(); j++)
		{
			if (v[i] > v[j])
				swap(v[i], v[j]);
		}
	}
}

//--------------------------------------------------------------------------------------
//插入排序：O(N^2) 稳定
void InsertSort(vector<int>& v)
{
	if (v.size() <= 1)
		return;

	for (int i = 0; i < v.size(); i++)
	{
		int tmp = v[i];               //为待插入的值
		int cur = i - 1;
		while (cur >= 0 && tmp < v[cur])  //在前面有序数组中去找合适的位置
		{
			v[cur + 1] = v[cur];
			cur--;
		}
		v[cur+1] = tmp;               //放在合适的位置上
	}
}

//--------------------------------------------------------------------------------------
//希尔排序：O(N^2) 不稳定
void ShellSort(vector<int>& v)
{
	if (v.size() <= 1)
		return;

	int gap = v.size() ;//步长

	//使用步长是，一定要从v.size()向下除，不能用2^N来向上计算，因为不能保证2^N一定是v.size()

	for (; gap > 0; gap /= 2)//步长控制
	{
		int cur = 0;
		for (; cur < gap; cur++)//每组起始元素
		{
			int bound = cur + gap;
			for (; bound < v.size() ; bound += gap)//插入排序，每个元素相间隔gap
			{
				int val = v[bound];
				int index = bound - gap;
				while (index >= 0 && val < v[index])
				{
					v[index + gap] = v[index];
					index -= gap;
				}
				v[index + gap] = val;
			}
		}
	}
}
int main()
{
	vector<int> v = { 9, 5, 2, 7, 4, 3, 8 };
	//Qsort1(v, 0, v.size() - 1);
	//Qsort2(v, 0, v.size() - 1);
	//HeapSort(v);
	//MergeSort( v);
	//BubbleSort(v);
	//SelectSort(v);
	//InsertSort(v);
	ShellSort(v);
	return 0;
}