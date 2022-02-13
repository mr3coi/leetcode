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
        vector<int> vals{};
        findModeHelper(root, vals);
        findModeFromVals(vals, ret);
        return ret;
    }

    void findModeHelper(TreeNode* curr, vector<int>& vals)
    {
        if (!curr)
        {
            return;
        }
        findModeHelper(curr->left, vals);
        vals.push_back(curr->val);
        findModeHelper(curr->right, vals);
    }

    void findModeFromVals(vector<int> const& vals, vector<int>& modes)
    {
        int lastCount{};
        int lastVal{std::numeric_limits<int>::min()};
        int maxCount{};
        for (int val : vals)
        {
            if (val != lastVal)
            {
                lastVal = val;
                lastCount = 0;
            }
            ++lastCount;
            if (lastCount == maxCount)
            {
                modes.push_back(lastVal);
            }
            else if (lastCount > maxCount)
            {
                modes.clear();
                modes.push_back(lastVal);
                maxCount = lastCount;
            }
        }
    }
};
