#pragma once
#include <stddef.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListCycleDetection
{
public:
	LinkedListCycleDetection();
	~LinkedListCycleDetection();
	void execute();
	bool hasCycleSlow(ListNode *head);
	bool hasCycle(ListNode *head);
	ListNode* getCycleMeetPoint(ListNode *head);
	ListNode* detectCycle(ListNode *head);
	ListNode* reverseList(ListNode* head);
};

