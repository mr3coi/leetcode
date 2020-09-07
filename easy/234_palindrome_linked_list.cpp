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
	inline size_t length(ListNode* head) {
		size_t out = 0;
		while (head) {
			++out;
			head = head->next;
		}
		return out;
	}

	bool isPalindrome(ListNode* head) {
		if (!(head and head->next)) return true;
		size_t listLen = length(head);
		std::stack<decltype(head->val)> hist;
		int i=0;
		for (; i<listLen/2; ++i) {
			hist.push(head->val);
			head = head->next;
		}
		if (listLen % 2 == 1) {
			++i;
			head = head->next;
		}
		for (; i<listLen; ++i) {
			if (head->val != hist.top()) return false;
			head = head->next;
			hist.pop();
		}
		return true;
	}
};
