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
		if (head == nullptr)
			return nullptr;

		ListNode* nextNode = head->next;
		while (nextNode != nullptr and nextNode->val == head->val) {
			ListNode* tmp = nextNode;
			nextNode = nextNode->next;
			delete tmp;
		}
		head->next = deleteDuplicates(nextNode);
		return head;
	}
}

int main() {
	return 0;
}
