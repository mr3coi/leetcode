/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode() : val(0), next(nullptr) {}
 *	 ListNode(int x) : val(x), next(nullptr) {}
 *	 ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* reverseListHelper(ListNode* curr, ListNode* tail) {
		ListNode* prev = curr->next;
		curr->next = tail;
		if (!prev) return curr;
		return reverseListHelper(prev, curr);
	}

	/**
	 * Recursion-based implementation.
	 * Should be returning ptr to the last node in the end.
	 */
	ListNode* reverseList(ListNode* head) {
		if (!head) return nullptr;
		return reverseListHelper(head, nullptr);
	}
};
