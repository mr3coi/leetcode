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

    int minDiffInBST(TreeNode* root)
    {
        int prev{-10000000}; // A small enough integer that does not overflow.
        int ret{INT_MAX};
        inOrderTraverse(root, prev, ret);
        return ret;
    }

    void inOrderTraverse(TreeNode* curr, int& prev, int& minDiff)
    {
        if (!curr)
        {
            return;
        }
        inOrderTraverse(curr->left, prev, minDiff);
        minDiff = std::min(curr->val - prev, minDiff);
        prev = curr->val;
        inOrderTraverse(curr->right, prev, minDiff);
    }
};
