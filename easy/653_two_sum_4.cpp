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

    bool findTarget(TreeNode* root, int k) {
        std::unordered_set<int> lookingFor{};
        return findHelper(root, k, lookingFor);
    }

    bool findHelper(TreeNode* curr, int k, std::unordered_set<int>& lookingFor)
    {
        if (!curr)
        {
            return false;
        }
        // Inorder traversal
        if (findHelper(curr->left, k, lookingFor))
        {
            return true;
        }
        if (lookingFor.find(curr->val) != lookingFor.end())
        {
            return true;
        }
        if (curr->val <= k / 2)
        {
            lookingFor.insert(k - curr->val);
        }
        return findHelper(curr->right, k, lookingFor);
    }
};
