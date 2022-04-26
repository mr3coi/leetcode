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
        if (!root)
        {
            return INT_MAX;
        }
        auto leftMinDiff{INT_MAX};
        if (root->left)
        {
            auto leftMax = endVal(root->left, false);
            leftMinDiff = std::min(minDiffInBST(root->left), root->val - leftMax);
        }
        auto rightMinDiff{INT_MAX};
        if (root->right)
        {
            auto rightMin = endVal(root->right, true);
            rightMinDiff = std::min(minDiffInBST(root->right), rightMin - root->val);
        }
        return std::min(leftMinDiff, rightMinDiff);
    }

    int endVal(TreeNode* subroot, bool findMin)
    {
        if (findMin)
        {
            while (subroot->left)
            {
                subroot = subroot->left;
            }
        }
        else // findMax
        {
            while (subroot->right)
            {
                subroot = subroot->right;
            }
        }
        return subroot->val;
    }
};
