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
    struct NodeWrapper
    {
        NodeWrapper(TreeNode* node_) : node(node_) {}
        NodeWrapper(NodeWrapper const& nw) : node(nw.node), visited(nw.visited) {}
        void visit() { visited = true; }
        TreeNode* left() { return node->left; }
        TreeNode* right() { return node->right; }
        TreeNode* node{nullptr};
        bool visited{false};
    };

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret{};
        std::stack<NodeWrapper> s;
        s.emplace(root);
        while (!s.empty())
        {
            NodeWrapper n{s.top()};
            s.pop();
            if (!n.visited && n.node != nullptr)
            {
                n.visit();
                s.emplace(n.right());
                s.push(n);
                s.emplace(n.left());
            }
            else if (n.node != nullptr)
            {
                ret.push_back(n.node->val);
            }
        }
        return ret;
    }
};
