class Solution {
public:
	bool hasPathSumHelper(const TreeNode* curr, int targetSum, int currSum) {
		if (!curr) return false;
		currSum += curr->val;
		if (!(curr->left or curr->right)) {
			return currSum == targetSum;
		}
		else {
			return hasPathSumHelper(curr->left,targetSum,currSum)
				or hasPathSumHelper(curr->right,targetSum,currSum);
		}
	}

	bool hasPathSum(TreeNode* root, int sum) {
		return hasPathSumHelper(root, sum, 0);
	}
};
