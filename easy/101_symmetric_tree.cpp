#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		return root == nullptr || isMirror(root->left, root->right);
	}

	bool isMirror(TreeNode *leftTree, TreeNode *rightTree) {
		if (leftTree == nullptr && rightTree == nullptr) {
			return true;
		}
		if (leftTree == nullptr || rightTree == nullptr) {
			return false;
		}
		else if (leftTree->val != rightTree->val) {
			return false;
		}
		return isMirror(leftTree->left, rightTree->right) &&
			   isMirror(leftTree->right, rightTree->left);
	}
};

int main() {
	return 0;
}
