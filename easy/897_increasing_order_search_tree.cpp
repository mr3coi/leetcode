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

    // Find the rightmost end of an increasing BST.
    // Assumes that the BST with the given root is already increasing.
    TreeNode* findRightMost(TreeNode* root)
    {
        while (root->right)
        {
            root = root->right;
        }
        return root;
    }

    TreeNode* increasingBST(TreeNode* root)
    {
        if (!root)
        {
            return nullptr;
        }
        root->left = increasingBST(root->left);
        root->right = increasingBST(root->right);
        auto* newRoot = root->left;
        if (newRoot)
        {
            auto* rightOfLeftTree = findRightMost(root->left);
            rightOfLeftTree->right = root;
            root->left = nullptr;
            return newRoot;
        }
        else
        {
            return root;
        }
    }
};
