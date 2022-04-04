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
    static long long const INT_MAX{std::numeric_limits<int>::max()};

    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int findSecondMinimumValue(TreeNode* root) {
        // It is guaranteed that root != nullptr.
        auto ret = findHelper(root);
        return ret > INT_MAX ? -1 : static_cast<int>(ret);
    }

    // Idea: 2nd minimum of the subtree must be one of
    //       {curr, curr->left, curr->right, 2nd_min_of_left_subtree,
    //        2nd_min_of_right_subtree}
    long long findHelper(TreeNode* curr)
    {
        std::set<long long> values{};
        values.insert(curr->val);
        values.insert(INT_MAX + 1);
        if (curr->left)
        {
            values.insert(curr->left->val);
            values.insert(findHelper(curr->left));
        }
        if (curr->right)
        {
            values.insert(curr->right->val);
            values.insert(findHelper(curr->right));
        }
        // At least two values are guaranteed to be always in values.
        return *(++values.begin());
    }
};
