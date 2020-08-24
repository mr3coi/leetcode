/* Without using recursion */

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;

		ListNode *curr = head, *next = head->next;
		while (curr != nullptr) {
			if (next == nullptr or curr->val != next->val) {
				curr->next = next;
				curr = next;
			} else {
				next = next->next;
			}
		}
		return head;
	}
};

int main() {
	return 0;
}
