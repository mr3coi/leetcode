/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *tail = head;
		while (head and head->next) {
			head = head->next->next;
			tail = tail->next;
			if (head == tail) return true;
		}
		return false;
	}
};
