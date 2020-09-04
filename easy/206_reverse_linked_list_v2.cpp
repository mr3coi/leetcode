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
	/**
	 * Iteration-based implementation.
	 */
	ListNode* reverseList(ListNode* head) {
		if (!head) return nullptr;
		ListNode* last = nullptr;
		while (head) {
			ListNode* next = head->next;
			head->next = last;
			last = head;
			head = next;
		}
		return last;
	}
};
