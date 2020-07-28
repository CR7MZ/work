#include <iostream>
using namespace std;

struct ListNode {
	ListNode(const int& x)
		:val(x)
		,next(nullptr)
	{}
	int val;
	ListNode* next;
};
//题目：https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
//解析：应考虑到头结点为删除结点
class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head->val == val)
			return head->next;
		ListNode* cur = head->next;
		ListNode* close = head;
		while (cur->val != val){
			close = cur;
			cur = cur->next;
		}
		close->next = cur->next;
		delete cur;
		cur = nullptr;
		return head;
	}
};