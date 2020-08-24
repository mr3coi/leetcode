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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == nullptr and q == nullptr) {
			return true;
		}
		else if ((p == nullptr and q != nullptr) or (p != nullptr and q == nullptr)) {
			return false;
		}
		return (p->val == q->val and 
				isSameTree(p->left,q->left)) and
				isSameTree(p->right,q->right);
	}
};

int main() {
	return 0;
}
