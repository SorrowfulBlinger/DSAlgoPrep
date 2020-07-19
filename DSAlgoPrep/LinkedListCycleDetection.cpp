#include "pch.h"
#include "LinkedListCycleDetection.h"
#include <set>
#include <iostream>

LinkedListCycleDetection::LinkedListCycleDetection()
{
}


LinkedListCycleDetection::~LinkedListCycleDetection()
{
}

ListNode* LinkedListCycleDetection::getCycleMeetPoint(ListNode *head) {
	if (head == nullptr) {
		return nullptr;
	}

	ListNode *fast = head;
	ListNode *slow = head;

	bool hasCycle;
	ListNode* meet = NULL;
	while (1) {

		if (fast->next == NULL || fast->next->next == NULL) {
			hasCycle = false;
			break;
		}

		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow) {
			hasCycle = true;
			meet = slow;
			break;
		}

	}
	return meet;
}

ListNode* LinkedListCycleDetection::detectCycle(ListNode *head) {

	ListNode * meetR = getCycleMeetPoint(head);
	if (meetR != NULL) {
		ListNode * meetL = head;
		std::cout << "R:" << meetR->val;
		while (meetR != meetL) {
			meetR = meetR->next;
			meetL = meetL->next;
		}
		return meetL;
	}
	else {
		return NULL;
	}
}

void LinkedListCycleDetection::execute() {
	ListNode *head = new ListNode(10);
	ListNode *curr = head;
	for (int i = 0; i < 5; i++) {
		auto node = new ListNode(i);
		curr->next = node;
		curr = node;
	}
	curr->next = head;
	std::cout << "\n\n********************* Has Cycle - " << (hasCycle(head) == true ? "true" : "false");

	std::cout << "\n\n********************* Reverse list [10,0,1,2,3,4] - ";
	curr->next = nullptr;

	head = reverseList(head);
	while (head != nullptr) {
		std::cout << head->val << ",";
		head = head->next;
	}

}

ListNode* LinkedListCycleDetection::reverseList(ListNode* head) {

	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	else if (head->next->next == nullptr) {
		ListNode * newHead = head->next;
		newHead->next = head;
		head->next = nullptr;
		head = newHead;
		return head;
	}

	ListNode *curr = head;
	ListNode *next = curr->next;
	ListNode *nnext = next->next;
	ListNode *prev = nullptr;
	bool odd = false;
	while (curr != nullptr) {
		if (next != nullptr) {
			next->next = curr;
		}
		else {
			odd = true;
			break;
		}
		curr->next = prev;
		prev = next;

		curr = nnext;
		next = curr != nullptr ? curr->next : nullptr;
		nnext = next != nullptr ? next->next : nullptr;
	}

	if (!odd) {
		head = prev;
	}
	else {
		curr->next = prev;
		head = curr;
	}
	return head;
}

bool LinkedListCycleDetection::hasCycleSlow(ListNode *head) {
	if (!head) {
		return false;
	}

	/* std::set<ListNode*> visited;
	 Generic ptr */
	std::set<void*> visited;

	ListNode *curr = head;
	bool hasCycle = false;
	while (true) {
		if (visited.find(curr) != visited.end()) {
			hasCycle = true;
			break;
		}
		else {
			visited.insert(curr);
		}
		if (curr->next == NULL) {
			break;
		}
		else {
			curr = curr->next;
		}
	}
	return hasCycle;
}

bool LinkedListCycleDetection::hasCycle(ListNode *head) {
	if (!head) {
		return false;
	}
	ListNode *slow = head;
	ListNode *fast = head;
	bool hasCycle = false;
	while (true) {
		if (fast->next == NULL || fast->next->next == NULL) {
			hasCycle = false;
			break;
		}

		slow = slow->next;
		fast = fast->next->next;

		// Having this below to make sure start condition is handles as both point to head on start
		if (fast->next == slow || slow == fast) {
			hasCycle = true;
			break;
		}
	}
	return hasCycle;
}