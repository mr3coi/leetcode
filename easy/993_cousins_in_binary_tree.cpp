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
class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(#nodes)
    // Space complexity: O(#nodes)
    bool isCousins(TreeNode* root, int x, int y)
    {
        // Base cases
        if (!root || root->val == x || root->val == y)
        {
            return false;
        }

        // (curr, parent, level)
        std::queue<std::tuple<TreeNode*, TreeNode*, int>> q;

        TreeNode* xParent{};
        TreeNode* yParent{};
        int currLevel{};
        q.push({root, nullptr, currLevel});

        // Run BST to examine nodes of the same depth.
        while (!q.empty())
        {
            auto const& curr = q.front();
            // Upon finishing one depth
            if (std::get<2>(curr) > currLevel)
            {
                // Nodes x and y are found at the same depth.
                if (xParent && yParent)
                {
                    return xParent != yParent;
                }
                // Nodes x and y are not at the same depth.
                else if (!xParent != !yParent)
                {
                    return false;
                }
                // Update the level that is being examined.
                currLevel = std::get<2>(curr);
            }
            auto* const currNode = std::get<0>(curr);
            if (currNode)
            {
                if (currNode->val == x)
                {
                    xParent = std::get<1>(curr);
                }
                if (currNode->val == y)
                {
                    yParent = std::get<1>(curr);
                }
                q.push({currNode->left,  currNode, currLevel + 1});
                q.push({currNode->right, currNode, currLevel + 1});
            }
            q.pop();
        }
        // Shouldn't reach here.
        return false;
    }
};
