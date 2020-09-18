#include <vector>
#include <queue>
using namespace std;
//题目：https://leetcode-cn.com/problems/smallest-k-lcci/

//使用优先级队列，大堆。若要找出最大的K个数，使用小堆即可。
vector<int> smallestK(vector<int>& arr, int k) {
	if (k == 0) return{};
	priority_queue<int> p;
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		p.push(arr[i]);
	}
	for (int i = k; i < arr.size(); ++i) {
		if (arr[i] < p.top()) {
			p.pop();
			p.push(arr[i]);
		}
	}
	for (int i = 0; i < k; ++i) {
		ans.push_back(p.top());
		p.pop();
	}
	return ans;
}