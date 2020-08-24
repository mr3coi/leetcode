class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (!(root->left or root->right)) {
			return root->val == sum;
		}
		else {
			return hasPathSum(root->left, sum-root->val)
				or hasPathSum(root->right,sum-root->val);
		}
	}
};
