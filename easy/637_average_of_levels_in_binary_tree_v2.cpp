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

    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ret{};
        if (!root)
        {
            return ret;
        }
        std::queue<TreeNode const*> q;
        q.push(root);
        auto const pushChildIfNotNull = [&q](TreeNode const* const child) {
            if (child)
            {
                q.push(child);
            }
        };
        while (!q.empty())
        {
            auto nbNodesInLevel = q.size();
            double levelSum{};
            for (size_t i = 0; i < nbNodesInLevel; ++i)
            {
                auto const* const n = q.front();
                levelSum += n->val;
                pushChildIfNotNull(n->left);
                pushChildIfNotNull(n->right);
                q.pop();
            }
            ret.push_back(levelSum /= nbNodesInLevel);
        }
        return ret;
    }
};
