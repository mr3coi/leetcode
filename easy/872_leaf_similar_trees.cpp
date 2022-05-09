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

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> leaves1{};
        std::vector<int> leaves2{};
        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }

    // In-order traversal
    void collectLeaves(TreeNode* curr, std::vector<int>& ret)
    {
        if (!curr)
        {
            return;
        }
        if (!curr->left && !curr->right)
        {
            ret.push_back(curr->val);
        }
        else
        {
            collectLeaves(curr->left, ret);
            collectLeaves(curr->right, ret);
        }
    }
};
