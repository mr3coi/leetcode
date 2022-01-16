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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret{};
        inorderTraversalHelper(root, ret);
        return ret;
    }

    void inorderTraversalHelper(TreeNode* root, vector<int>& ret)
    {
        if (!root)
        {
            return;
        }
        inorderTraversalHelper(root->left, ret);
        ret.push_back(root->val);
        inorderTraversalHelper(root->right, ret);
    }
};
