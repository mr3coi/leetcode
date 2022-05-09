/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    ListNode* middleNode(ListNode* head) {
        if (!head->next)
        {
            return head;
        }
        ListNode* twice{head};
        while (twice->next && twice->next->next)
        {
            head = head->next;
            twice = twice->next->next;
        }
        return twice->next ? head->next : head;
    }
};
