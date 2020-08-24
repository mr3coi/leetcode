/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution {
public:
	bool isBalancedHelper(std::stack<int>& heights, TreeNode* root) {
		if (root == nullptr) {
			heights.push(0);
			return true;
		}

		if (isBalancedHelper(heights, root->left) and isBalancedHelper(heights, root->right)) {
			int val1 = heights.top();
			heights.pop();
			int val2 = heights.top();
			heights.pop();
			if (val1-val2 > 1 or val1-val2 < -1) return false;
			heights.push(std::max(val1,val2)+1);
			return true;
		}
		return false;
	}

    bool isBalanced(TreeNode* root) {
		std::stack<int> heights;
		return isBalancedHelper(heights, root);
    }
};
