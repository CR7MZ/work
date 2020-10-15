#include <iostream>
#include <vector>
using namespace std;

//题目：常考：将数组中的负数放在最左变，0放在中间，正数放在右边

//思路：进行两次快排
void Func1(vector<int>& v){
	int left = 0, mid = 0, right = v.size() - 1;
	while (left < right){
		while (left < right && v[left] <= 0) left++;
		while (left < right && v[right] > 0) right--;

		if (left < right){
			swap(v[left], v[right]);
		}
	}

	left = 0, mid = right-1;
	while (left < mid){
		while (left < mid && v[left] < 0) left++;
		while (left < mid && v[mid] == 0) mid--;

		if (left < mid){
			swap(v[left], v[mid]);
		}
	}
}

//思路：若v[mid] < 0 ，将数据扔到left前面。若v[mid] > 0 ，将数据扔到right后面。
void Func2(vector<int>& v){
	int left = 0, mid = 0, right = v.size() - 1;
	//left最终指向的是负数区域的最后一个位置的下一个位置（0区域的第一个数）。
	//mid最终指向的是0区域的最后一个位置的下一个位置（正数区域的第一个数）。
	//right最终指向的是正数区域的第一个位置的前一个位置（0区域的最后一个位置）。

	while (mid <= right){
		if (v[mid] < 0){                //因为交换完之后的v[mid]值一定是0区域的所以可以mid++。
			swap(v[left], v[mid]);
			left++;mid++;
		} else if (v[mid] == 0){
			mid++;
		} else {
			swap(v[right], v[mid]);     //因为交换完之后的v[mid]值不清楚属于哪个区域，因此mid不能移动。
			right--;
		}
	}
}

int main(){
	vector<int> v = { 0, 2, 4, 3, 1, 0, -3, -1, -2 };
	Func1(v);
	for (auto e : v){
		cout << e;
	}
	cout << endl;
	return 0;
}