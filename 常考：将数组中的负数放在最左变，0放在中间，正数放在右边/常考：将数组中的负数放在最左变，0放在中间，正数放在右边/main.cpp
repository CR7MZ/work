#include <iostream>
#include <vector>
using namespace std;

//��Ŀ���������������еĸ�����������䣬0�����м䣬���������ұ�

//˼·���������ο���
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

//˼·����v[mid] < 0 ���������ӵ�leftǰ�档��v[mid] > 0 ���������ӵ�right���档
void Func2(vector<int>& v){
	int left = 0, mid = 0, right = v.size() - 1;
	//left����ָ����Ǹ�����������һ��λ�õ���һ��λ�ã�0����ĵ�һ��������
	//mid����ָ�����0��������һ��λ�õ���һ��λ�ã���������ĵ�һ��������
	//right����ָ�������������ĵ�һ��λ�õ�ǰһ��λ�ã�0��������һ��λ�ã���

	while (mid <= right){
		if (v[mid] < 0){                //��Ϊ������֮���v[mid]ֵһ����0��������Կ���mid++��
			swap(v[left], v[mid]);
			left++;mid++;
		} else if (v[mid] == 0){
			mid++;
		} else {
			swap(v[right], v[mid]);     //��Ϊ������֮���v[mid]ֵ����������ĸ��������mid�����ƶ���
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