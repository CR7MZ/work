#include <iostream>
using namespace std;

//题目：https://leetcode-cn.com/problems/insertion-sort-list/
//解析：新建一个链表，表示已经有序的链表，表头结点为newhead。每次用使用原链表head指向的元素与newhead链表中每个元素比较找到合适的位置
//将原来链表head指向的结点删除插入新链表对应的位置

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* newhead = new ListNode(0);
		while (head){
			auto p = newhead;
			while (p->next && p->next->val < head->val) p = p->next;
			auto q = head;
			head = head->next;

			q->next = p->next;
			p->next = q;
		}
		return newhead->next;
	}

};