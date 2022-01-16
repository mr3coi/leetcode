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
    struct WNode
    {
        WNode(TreeNode* node_) : node{node_}, visited{false} {}
        WNode(WNode const& other) : node{other.node}, visited{other.visited} {}
        TreeNode* left() { return node->left; }
        TreeNode* right() { return node->right; }
        void visit() { visited = true; }

        TreeNode* node;
        bool visited{false};
    };

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret{};
        std::stack<WNode> s{};
        if (root)
        {
            s.emplace(root);
            while (!s.empty())
            {
                WNode n{s.top()};
                s.pop();
                if (!n.visited && n.node != nullptr)
                {
                    n.visit();
                    s.push(n);
                    s.emplace(n.right());
                    s.emplace(n.left());
                }
                else if (n.node != nullptr)
                {
                    ret.push_back(n.node->val);
                }
            }
        }
        return ret;
    }
};
