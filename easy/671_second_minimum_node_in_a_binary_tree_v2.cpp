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
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int findSecondMinimumValue(TreeNode* root) {
        long long secondMin{INT_MAX + 1LL};
        // DFS - visit each node, find minimum that is larger than root.
        std::stack<TreeNode*> st{};
        st.push(root);
        while (!st.empty())
        {
            auto const* curr = st.top();
            st.pop();
            if (!curr)
            {
                continue;
            }
            if (curr->val != root->val)
            {
                secondMin = std::min(static_cast<long long>(curr->val), secondMin);
            }
            st.push(curr->left);
            st.push(curr->right);
        }
        return secondMin > INT_MAX ? -1 : static_cast<int>(secondMin);
    }
};
