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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret{};
        postorderTraversalHelper(root, ret);
        return ret;
    }

    void postorderTraversalHelper(TreeNode* node, vector<int>& ret)
    {
        if (!node)
        {
            return;
        }
        postorderTraversalHelper(node->left, ret);
        postorderTraversalHelper(node->right, ret);
        ret.push_back(node->val);
    }
};
