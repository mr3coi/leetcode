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

    std::string tree2str(TreeNode* root) {
        std::ostringstream o;
        // Presence of root is guaranteed.
        helper(o, root);
        return o.str();
    }

    void helper(std::ostringstream& o, TreeNode const* const curr)
    {
        auto const handleChild = [&](TreeNode const* const child, bool const mustPrint) {
            if (mustPrint || child)
            {
                o << '(';
                if (child)
                {
                    helper(o, child);
                }
                o << ')';
            }
        };
        o << curr->val;
        handleChild(curr->left, curr->right != nullptr);
        handleChild(curr->right, false);
    }
};
