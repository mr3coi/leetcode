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

    int findTilt(TreeNode* root) {
        int dummySum{};
        return helper(root, dummySum);
    }

    // Returns the sum of all tilts in the given subtree.
    // Also populates `currSum` with the sum of the subtree.
    int helper(TreeNode* curr, int& currSum)
    {
        if (!curr)
        {
            currSum = 0;
            return 0;
        }
        int leftSum{};
        int rightSum{};
        int leftTilt{helper(curr->left, leftSum)};
        int rightTilt{helper(curr->right, rightSum)};
        currSum = leftSum + rightSum + curr->val;
        return leftTilt + rightTilt + std::abs(leftSum - rightSum);
    }
};
