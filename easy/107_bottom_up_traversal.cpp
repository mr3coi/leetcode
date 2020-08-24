#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		vector<vector<int>> out;
		if (root == nullptr) return out;

		lOBHelper(root, 1, out);	// root has depth 1
		reverse(out.begin(), out.end());
		return out;
	}

	void lOBHelper(TreeNode *curr, int depth, vector<vector<int>>& out) {
		if (curr == nullptr) return;

		if (out.size() < depth) out.push_back(vector<int>());
		vector<int>& target = out.at(depth-1);
		target.push_back(curr->val);
		lOBHelper(curr->left, depth+1, out);
		lOBHelper(curr->right, depth+1, out);
	}
};

int main() {
	return 0;
}
