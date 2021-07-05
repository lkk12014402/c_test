// Author: kaokao
// Date: 2021-07-05
/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * for example,
 *
 *     Given linked list: 1->2->3->4->5, and n = 2.
 *
 *     After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 *
 * */

/**
 * Definition for singly-linked list.
 **/
#include <iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x, ListNode* node) : val(x), next(node) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* dummy = new ListNode(0, head);
	ListNode* first = head;
	ListNode* second = dummy;
	for (int i = 0; i < n; i++) {
	    first = first->next;
	}
	while (first) {
	    first = first->next;
	    second = second->next;
	}
	second->next = second->next->next;
	delete dummy;
	return head;
    }
};

int main() {
    ListNode *head;
    ListNode *curr, *prev;
    head = curr = prev = new ListNode(1, NULL);
    
    for (int i = 2; i < 6; i++) {
        curr = new ListNode(i, NULL);
	if (i == 1) head = curr;
	prev->next = curr;
	prev = curr;
    }
    curr = head;
    while (curr) {
        cout << curr->val << endl;
	curr = curr->next;
    }
    cout << "delete 2th from the end......" << endl;
    Solution solution;
    curr = solution.removeNthFromEnd(head, 2);
    while (curr) {
	cout << curr->val << endl;
	curr = curr->next;
    }

    return 0;
}

