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
    vector<int> findMode(TreeNode* root) {
        vector<int> ret{};
        int maxCount{};
        int lastCount{-1};
        int lastVal{std::numeric_limits<int>::min()};
        findModeHelper(root, ret, maxCount, lastVal, lastCount);
        return ret;
    }

    void findModeHelper(TreeNode* curr, vector<int>& modes, int& maxCount,
            int& lastVal, int& lastCount)
    {
        if (!curr)
        {
            return;
        }
        findModeHelper(curr->left, modes, maxCount, lastVal, lastCount);
        findModeInStream(curr->val, modes, maxCount, lastVal, lastCount);
        findModeHelper(curr->right, modes, maxCount, lastVal, lastCount);

    }

    void findModeInStream(int val, vector<int>& modes, int& maxCount,
            int& lastVal, int& lastCount)
    {
        if (val != lastVal)
        {
            lastVal = val;
            lastCount = 0;
        }
        ++lastCount;
        if (lastCount == maxCount)
        {
            modes.push_back(val);
        }
        else if (lastCount >= maxCount + 1)
        {
            if (lastCount == maxCount + 1)
            {
                modes.clear();
                modes.push_back(val);
            }
            maxCount = lastCount;
        }
    }
};
