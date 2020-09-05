/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	 int val;
 *	 TreeNode *left;
 *	 TreeNode *right;
 *	 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	/** Recursion-based approach */
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return nullptr;
		TreeNode* leftTree  = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(leftTree);
		return root;
	}
};
