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
	bool isPalindrome(ListNode* head) {
		if (!(head and head->next)) return true;

		// Find middle node of linked list
		ListNode *slow = head, *fast = head;
		while (fast and fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		// Move `slow` to start of later half
		// (if length is even (`fast` == nullptr); `slow` is at start of second half,
		//  if length is odd  (`fast` != nullptr); `slow` is at the middle node)
		if (fast) slow = slow->next;

		// Reverse later half of linked list
		// (`prev` becomes head of reversed list)
		ListNode* prev = nullptr;
		while (slow) {
			ListNode* next = slow->next;
			slow->next = prev;
			prev = slow;
			slow = next;
		}

		// Compare two halves of linked list
		while (prev) {
			if (head->val != prev->val) return false;
			head = head->next;
			prev = prev->next;
		}
		
		return true;
	}
};
