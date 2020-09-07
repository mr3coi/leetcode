/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	 int val;
 *	 TreeNode *left;
 *	 TreeNode *right;
 *	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* larger  = p->val > q->val ? p : q;
		TreeNode* smaller = p->val > q->val ? q : p;
		if (root->val < smaller->val) return lowestCommonAncestor(root->right, p, q);
		else if (root->val > larger->val) return lowestCommonAncestor(root->left, p, q);
		else return root;
	}
};
