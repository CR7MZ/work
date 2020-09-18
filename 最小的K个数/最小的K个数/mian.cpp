#include <vector>
#include <queue>
using namespace std;
//��Ŀ��https://leetcode-cn.com/problems/smallest-k-lcci/

//ʹ�����ȼ����У���ѡ���Ҫ�ҳ�����K������ʹ��С�Ѽ��ɡ�
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