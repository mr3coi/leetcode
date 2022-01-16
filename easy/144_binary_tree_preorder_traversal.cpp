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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret{};
        preorderTraversalHelper(root, ret);
        return ret;
    }

    void preorderTraversalHelper(TreeNode const* node, vector<int>& ret)
    {
        if (!node)
        {
            return;
        }
        ret.push_back(node->val);
        preorderTraversalHelper(node->left, ret);
        preorderTraversalHelper(node->right, ret);
    }
};
