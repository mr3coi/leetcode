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
class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(#nodes)
    // Space complexity: Theta(1)
    int sumRootToLeaf(TreeNode* root)
    {
        return helper(root, 0);
    }

    int helper(TreeNode* curr, int const parentSum)
    {
        if (!curr)
        {
            return 0;
        }
        int const currSum{parentSum * 2 + curr->val};
        if (!curr->left && !curr->right)
        {
            return currSum;
        }
        else
        {
            // Sum of all binaries whose ends are the leaves of the current node.
            return helper(curr->left, currSum) + helper(curr->right, currSum);
        }
    }
};
