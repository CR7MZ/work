#include <iostream>
using namespace std;

//ÌâÄ¿£ºhttps://leetcode-cn.com/problems/sort-list/submissions/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//¹é²¢
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		return mergesort(head);
	}

	ListNode* mergesort(ListNode* head){
		if (head == nullptr || head->next == nullptr) return head;

		ListNode* slow = head;
		ListNode* l = nullptr;
		ListNode* r = nullptr;
		ListNode* fast = head->next->next;
		while (fast != nullptr && fast->next != nullptr){
			slow = slow->next;
			fast = fast->next->next;
		}

		r = mergesort(slow->next);

		slow->next = nullptr;

		l = mergesort(head);
		return mergelist(l, r);
	}

	ListNode* mergelist(ListNode* l, ListNode* r){
		ListNode* tmp = new ListNode(-1);
		ListNode* p = tmp;
		while (l != nullptr && r != nullptr){
			if (l->val < r->val){
				p->next = l;
				l = l->next;
			}
			else {
				p->next = r;
				r = r->next;
			}
			p = p->next;
		}
		p->next = l == nullptr ? r : l;
		return tmp->next;
	}
};