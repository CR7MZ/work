//��Ŀ��
#include<iostream>
#include<vector>
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) 
		:val(x), next(nullptr){}
};
//����1��
//����һ���µ�ͷ����������ָ�룬�ֱ�ָ�����������ͷ�����бȽϡ�С�ķ����µ�ͷ���棬����γ��µ�����
ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr&&pHead2 == nullptr)
		return nullptr;
	ListNode* res = new struct ListNode(-1);
	ListNode* root = res;
	ListNode* cur1 = pHead1;
	ListNode* cur2 = pHead2;
	while (cur1 != nullptr&&cur2 != nullptr)
	{
		if (cur1->val<cur2->val)
		{
			ListNode* tmp = new struct ListNode(cur1->val);
			res->next = tmp;
			cur1 = cur1->next;
			res = tmp;
		}
		else if (cur1->val >= cur2->val)
		{
			ListNode* tmp = new struct ListNode(cur2->val);
			res->next = tmp;
			cur2 = cur2->next;
			res = tmp;
		}
	}
	if (cur1 == nullptr)
		res->next = cur2;
	if (cur2 == nullptr)
		res->next = cur1;
	return root->next;
}
//����2
//�Ƚ���һ�����飬�����������������ֵ���������� ��Ȼ������������������һ���µ�ͷ���������е�����ȫ���������С�
ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr&&pHead2 == nullptr)
		return nullptr;
	std::vector<int> v;
	ListNode* cur1 = pHead1;
	while (cur1 != nullptr)
	{
		v.push_back(cur1->val);
		cur1 = cur1->next;
	}
	ListNode* cur2 = pHead2;
	while (cur2 != nullptr)
	{
		v.push_back(cur2->val);
		cur2 = cur2->next;
	}
	for (size_t i = 0; i<v.size(); i++)
	{
		for (size_t j = 0; j<v.size() - 1; j++)
		{
			if (v[j]>v[j + 1])
			{
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
	ListNode* tmp = pHead1;
	tmp->val = v[0];
	for (size_t i = 1; i<v.size(); i++)
	{
		ListNode* re = new struct ListNode(v[i]);
		tmp->next = re;
		tmp = re;
	}
	return pHead1;
}