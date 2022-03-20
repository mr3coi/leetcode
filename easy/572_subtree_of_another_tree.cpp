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

    bool XOR(TreeNode* curr, TreeNode* subRoot)
    {
        return curr && !subRoot || !curr && subRoot;
    }

    bool isSameTree(TreeNode* curr, TreeNode* subRoot)
    {
        if (XOR(curr, subRoot))
        {
            return false;
        }
        if (!curr && !subRoot)
        {
            return true;
        }
        if (curr->val != subRoot->val)
        {
            return false;
        }
        return isSameTree(curr->left, subRoot->left) && isSameTree(curr->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (XOR(root, subRoot))
        {
            return false;
        }
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
