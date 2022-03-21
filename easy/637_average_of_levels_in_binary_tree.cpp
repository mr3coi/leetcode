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
        std::queue<std::pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        int nbNodesInLevel{0};
        int currLevel{0};
        auto const handleChild = [&q, &currLevel](TreeNode* child) {
            if (child)
            {
                q.emplace(child, currLevel+1);
            }
        };
        while (!q.empty())
        {
            auto kv = q.front();
            if (kv.second != currLevel)
            {
                ret.at(currLevel) /= nbNodesInLevel;
                nbNodesInLevel = 0;
                currLevel = kv.second;
                continue;
            }
            q.pop();
            if (!nbNodesInLevel)
            {
                ret.push_back(0);
            }
            ret.at(currLevel) += static_cast<double>(kv.first->val);
            ++nbNodesInLevel;
            handleChild(kv.first->left);
            handleChild(kv.first->right);
        }
        *(ret.end()-1) /= nbNodesInLevel;
        return ret;
    }
};
