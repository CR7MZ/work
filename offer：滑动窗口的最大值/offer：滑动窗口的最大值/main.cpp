#include <iostream>
#include <vector>
using namespace std;

//题目：https://www.nowcoder.com/questionTerminal/1624bc35a45c42c0bc17d17fa0cba788?f=discussion&toCommentId=6416068

//题目解析：
//先给出一个获取区间内最大值的下标的函数Func。定义两个指针left，right模拟窗口。
//1.起初，index为 - 1时，找出第一个窗口中最大值，并将其下标记录起来保存在index中，窗口向后移动。
//2.紧接着，因为移动后index有可能不在敞口中，此时分情况讨论：
//1.如果index在窗口中，那么只需要判断新加入窗口的值，也就是此时right指向的值是否大于index所 指向的值，如果大于，则更新index。否则index不变。
//2.如果index不在窗口中，那么重新去调用Func获取新的最大值，以及index。
class Solution {
public:
	int maxNum(const vector<int>& v, int left, int right)
	{
		int index = -1;
		int max = 0;
		for (int i = left; i <= right; i++){
			if (v[i] > max){
				index = i;
				max = v[i];
			}
		}
		return index;
	}
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> Maxes;
		int index = -1;
		int left = 0;
		int right = left + size - 1;
		while (right < num.size()){
			if (index == -1){
				index = maxNum(num, left, right);
				Maxes.push_back(num[index]);
			}
			else if (index >= left && index <= right){
				if (num[index] > num[right]){
					Maxes.push_back(num[index]);
				}
				else {
					index = right;
					Maxes.push_back(num[index]);
				}
			}
			else {
				index = maxNum(num, left, right);
				Maxes.push_back(num[index]);
			}
			++left;
			++right;
		}
		return Maxes;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector <int> res = s.maxInWindows(v,3);
	for (auto e : res){
		cout << e << endl;
	}
	system("pause");
	return 0;
}