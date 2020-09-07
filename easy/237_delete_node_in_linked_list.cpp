/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	/**
	 * Push all values of nodes following the one to be deleted forward by one,
	 * and delete the last node.
	 */
	void deleteNode(ListNode* node) {
		ListNode* next = node->next;
		while (next->next) {
			node->val = next->val;
			node = node->next;
			next = next->next;
		}
		// Stop when `node` is the second-last node
		node->val = next->val;
		node->next = nullptr;
	}
};
