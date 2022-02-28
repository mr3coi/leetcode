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

    int diameterOfBinaryTree(TreeNode* root) {
        int dummyHeight{};
        return helper(root, dummyHeight);
    }

    // Height refers to the number of *nodes* in the longest path in the subtree.
    int helper(TreeNode* curr, int& height)
    {
        if (!curr)
        {
            height = 0;
            return 0;
        }
        int leftHeight{-1}, rightHeight{-1};
        int leftDiameter = helper(curr->left, leftHeight);
        int rightDiameter = helper(curr->right, rightHeight);
        height = std::max(leftHeight, rightHeight) + 1;
        return std::max({leftHeight + rightHeight, leftDiameter, rightDiameter});
    }
};
