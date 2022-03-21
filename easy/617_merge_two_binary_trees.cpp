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

    TreeNode* mergeTrees(TreeNode const* const root1, TreeNode const* const root2)
    {
        if (!root1 && !root2)
        {
            return nullptr;
        }
        auto const getPtr = [](TreeNode const* const node, bool const left) {
            return node ? (left ? node->left : node->right) : nullptr;
        };
        auto const getVal = [](TreeNode const* const node) {
            return node ? node->val : 0;
        };
        auto newRoot = std::make_unique<TreeNode>();
        newRoot->val = getVal(root1) + getVal(root2);
        newRoot->left  = mergeTrees(getPtr(root1, true), getPtr(root2, true));
        newRoot->right = mergeTrees(getPtr(root1, false), getPtr(root2, false));
        return newRoot.release();
    }
};
