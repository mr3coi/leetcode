class Solution {
public:
	inline size_t length(const ListNode *head) {
		int out = 0;
		while (head) {
			++out;
			head = head->next;
		}
		return out;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		size_t lenA = length(headA), lenB = length(headB);
		if (lenA > lenB)
			for (int i=0; i<(lenA-lenB); ++i) headA = headA->next;
		else 
			for (int i=0; i<(lenB-lenA); ++i) headB = headB->next;
		while (headA) {
			if (headA == headB) return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return nullptr;
	}
};
