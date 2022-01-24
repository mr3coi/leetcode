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
    /*
     * Time complexity: O(#nodes)
     * Space complexity: Omega(1)
     */
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }

    int helper(TreeNode* node, bool isLeftOfParent)
    {
        if (!node) // For convenience
        {
            return 0;
        }
        else if (node->left || node->right) // Is not a leaf
        {
            return helper(node->left, true) + helper(node->right, false);
        }
        else // Is a leaf
        {
            return isLeftOfParent ? node->val : 0;
        }
    }
};
