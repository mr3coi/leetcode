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
	bool hasCycleHelper(ListNode *head, std::unordered_set<ListNode*>& alreadyVisited) {
		return head and (!std::get<1>(alreadyVisited.insert(head)) or hasCycleHelper(head->next, alreadyVisited));
	}

	bool hasCycle(ListNode *head) {
		std::unordered_set<ListNode*> alreadyVisited;
		return hasCycleHelper(head, alreadyVisited);
	}
};
