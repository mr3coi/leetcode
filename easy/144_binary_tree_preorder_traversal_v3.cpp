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
        std::stack<TreeNode*> s;
        auto const pushIfNotNull = [&s](TreeNode* n) {
            if (n)
            {
                s.push(n);
            }
        };
        pushIfNotNull(root);
        while (!s.empty())
        {
            TreeNode const* n{s.top()};
            s.pop();
            ret.push_back(n->val);
            pushIfNotNull(n->right);
            pushIfNotNull(n->left);
        }
        return ret;
    }
};
