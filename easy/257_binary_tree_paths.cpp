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
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) return {};
		if (!(root->left or root->right)) return {std::to_string(root->val)};

		std::vector<std::string> leftPaths = binaryTreePaths(root->left);
		std::vector<std::string> rightPaths = binaryTreePaths(root->right);
		leftPaths.reserve(leftPaths.size() + rightPaths.size());
		leftPaths.insert(leftPaths.end(), rightPaths.begin(), rightPaths.end());
		for (int i=0; i<leftPaths.size(); ++i) {
			leftPaths[i] = std::to_string(root->val) + "->" + leftPaths[i];
		}
		return leftPaths;
	}
};
