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

    // Time complexity: O(#nodes)
    // Space complexity: O(1) or O(#nodes) (due to function call stack)
    bool isUnivalTree(TreeNode* root)
    {
        // Protective measure.
        if (!root)
        {
            return true;
        }
        // All nodes must have the same value as root.
        return allNodesHaveValue(root, root->val);
    }

    bool allNodesHaveValue(TreeNode* root, int val)
    {
        if (!root)
        {
            return true;
        }
        if (root->val != val)
        {
            return false;
        }
        return allNodesHaveValue(root->left, val)
            && allNodesHaveValue(root->right, val);
    }
};
