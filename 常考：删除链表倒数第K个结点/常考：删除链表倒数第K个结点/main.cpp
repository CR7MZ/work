#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//��Ŀ��https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == nullptr)
		return head;
	ListNode* cur1 = head;
	ListNode* cur2 = head;
	ListNode* pre = cur1;  //��ǵ�ǰҪ��ɾ������ǰһ�����λ��

	int i = 1;
	while (cur2->next != nullptr){
		pre = cur1;
		if (i >= n)
			cur1 = cur1->next;

		cur2 = cur2->next;
		++i;
	}
	if (pre == cur1)            //�п�������Ҫɾ������ͷ���
		head = cur1->next;
	else
		pre->next = cur1->next;

	delete cur1;
	cur1 = nullptr;
	return head;
}