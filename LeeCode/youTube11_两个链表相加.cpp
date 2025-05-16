#include<iostream>
#include"ListNode.h"

using namespace std;

ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
	ListNode* ans = NULL;
	ListNode* cur = NULL;
	int carry = 0;
	for (int sum = 0, val = 0;
		h1 != NULL || h2 != NULL;
		h1 = h1 == NULL ? NULL : h1->next, h2 = h2 == NULL ? NULL : h2->next) {

		sum = (h1 == NULL ? 0 : h1->val) + (h2 == NULL ? 0 : h2->val) + carry;
		carry = sum / 10;
		val = sum % 10;

		if (ans == NULL) {
			ans = new ListNode(val);
			cur = ans;
		}
		else {
			(*cur).next = new ListNode(val);
			cur = cur->next;
		}

	}
	if (carry == 1) {
		cur->next = new ListNode(1);
		cur = cur->next;
	}
	return ans;
}

int main() {
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode* result = addTwoNumbers(l1, l2);
	ListNode* cur = result;
	while (cur != nullptr) {
		cout << cur->val << " ";
		cur = cur->next;
	}

	return 0;
}

