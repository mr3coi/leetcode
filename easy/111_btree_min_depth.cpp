class Solution {
public:
    int minDepth(TreeNode* root) {
		if (!root) return 0;
		std::queue<std::pair<TreeNode*,int>> nodeQ;
		int depth = -1;
		TreeNode* curr = nullptr;

		nodeQ.push(std::make_pair(root,1));
		while (!nodeQ.empty()) {
			std::tie(curr,depth) = nodeQ.front();
			nodeQ.pop();
			if (not(curr->left or curr->right)) break;
			if (curr->left) nodeQ.push(std::make_pair(curr->left, depth+1));
			if (curr->right) nodeQ.push(std::make_pair(curr->right, depth+1));
		}
		return depth;
    }
};
