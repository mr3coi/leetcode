/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    static int const VISITED{INT_MIN};
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::stack<TreeNode*> st1{};
        std::stack<TreeNode*> st2{};
        st1.push(root1);
        st2.push(root2);
        bool ready1{false};
        bool ready2{false};
        while (!st1.empty() && !st2.empty())
        {
            if (ready1 && ready2)
            {
                if (st1.top()->val != st2.top()->val)
                {
                    return false;
                }
                st1.pop();
                st2.pop();
                ready1 = false;
                ready2 = false;
            }
            else if (!ready1)
            {
                auto* top1 = st1.top();
                if (top1->val == VISITED)
                {
                    st1.pop();
                    continue;
                }
                if (!top1->left && !top1->right)
                {
                    ready1 = true;
                    continue;
                }
                if (top1->right)
                {
                    // Mark directly on the given tree.
                    top1->val = VISITED;
                    st1.push(top1->right);
                }
                // Placed left after right so that left subtree is visited first.
                if (top1->left)
                {
                    top1->val = VISITED;
                    st1.push(top1->left);
                }
            }
            else
            {
                auto* top2 = st2.top();
                if (top2->val == VISITED)
                {
                    st2.pop();
                    continue;
                }
                if (!top2->left && !top2->right)
                {
                    ready2 = true;
                    continue;
                }
                if (top2->right)
                {
                    top2->val = VISITED;
                    st2.push(top2->right);
                }
                // Placed left after right so that left subtree is visited first.
                if (top2->left)
                {
                    top2->val = VISITED;
                    st2.push(top2->left);
                }
            }
        }
        // Tree 1 should have been fully traversed at this point.
        if (ready1 || !st1.empty())
        {
            return false;
        }
        // Tree 2 should also have all its leaves visited by this time.
        while (!st2.empty())
        {
            auto* top1 = st2.top();
            if (top->val == VISITED)
            {
                st2.pop();
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
