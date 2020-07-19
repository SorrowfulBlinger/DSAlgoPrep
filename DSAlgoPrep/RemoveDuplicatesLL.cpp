#include "pch.h"
#include "RemoveDuplicatesLL.h"
#include <iostream>

RemoveDuplicatesLL::RemoveDuplicatesLL()
{
}


RemoveDuplicatesLL::~RemoveDuplicatesLL()
{
}

void RemoveDuplicatesLL::execute() {
	ListNode *head = new ListNode(10);
	ListNode *curr = head;
	for (int i = 0; i < 5; i++) {
		auto node = new ListNode(i==3 ? 2:i);
		curr->next = node;
		curr = node;
	}
	std::cout << "\n\n********************* Remove duplicates List - ";
	std::cout << "\n********************* Actual List - 10, 0, 1, 2, 2, 4";
	std::cout << "\n********************* Trimmed List - ";
	head = deleteDuplicates(head);
	
	while (head != nullptr) {
		std::cout << head->val << ", ";
		head = head->next;
	}
}

ListNode* RemoveDuplicatesLL::deleteDuplicates(ListNode* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	ListNode* curr = head;
	ListNode* prev = nullptr;

	while (curr != nullptr) {
		if (curr->next != nullptr && curr->val == curr->next->val) {
			ListNode *tracker = curr->next->next;
			while (tracker != nullptr && tracker->val == curr->val) {
				tracker = tracker->next;
			}
			if (curr == head) {
				head = tracker;
			}
			curr = tracker;
			if (prev != nullptr) {
				prev->next = curr;
			}
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
	return head;
}