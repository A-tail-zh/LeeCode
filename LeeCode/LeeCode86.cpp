#include<iostream>
#include "ListNode.h"
using namespace std;

ListNode* partition(ListNode* head, int x) {
	ListNode* sHead = NULL, * sTail = NULL;
	ListNode* bHead = NULL, * bTail = NULL;
	ListNode* next = NULL;
	while (head!= NULL) {
		next = head->next;
		head->next = NULL;
		if (head->val < x) {
			//�ӵ�С��������
			if (sHead == NULL) {
				sHead = head;
			}
			else
			{
				sTail->next = head;
			}
			sTail = head;
		}
		else {
			//�ӵ����������
			if (bHead == NULL) {
				bHead = head;
			}
			else
			{
				bTail->next = head;
			}
			bTail = head;
		}


		head = next;
	}
	if (sTail == NULL) return bHead;
	sTail->next = bHead;

	return sHead;
}



int main() {
	return 0;
}