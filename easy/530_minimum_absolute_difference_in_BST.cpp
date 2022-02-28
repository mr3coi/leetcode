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
    int lastVal{std::numeric_limits<int>::max()};
    static int const MAX_DIFF{std::numeric_limits<int>::max()};

public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Returns the minimum difference of the subtree represented by root.
    int getMinimumDifference(TreeNode* root) {
        if (!root)
        {
            return MAX_DIFF;
        }
        int minDiffSoFar = getMinimumDifference(root->left);
        minDiffSoFar = std::min(minDiffSoFar, std::abs(root->val - lastVal));
        lastVal = root->val;
        return std::min(minDiffSoFar, getMinimumDifference(root->right));
    }
};
