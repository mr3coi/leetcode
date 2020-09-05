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
	/** Iterative approach using BFS */
	TreeNode* invertTree(TreeNode* root) {
		std::queue<TreeNode*> bfsQueue;
		bfsQueue.push(root);
		while (!bfsQueue.empty()) {
			TreeNode* curr = bfsQueue.front();
			bfsQueue.pop();
			if (curr) {
				TreeNode* left = curr->left;
				curr->left = curr->right;
				curr->right = left;
				bfsQueue.push(curr->left);
				bfsQueue.push(curr->right);
			}
		}
		return root;
	}
};
