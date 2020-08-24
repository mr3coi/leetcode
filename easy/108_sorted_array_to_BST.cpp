class Solution {
public:
	TreeNode* sortedArrayToBSTImpl(vector<int>& nums, unsigned int start, unsigned int end) {
		unsigned int size = end - start;
		if (!size) return nullptr;
		if (size == 1) return new TreeNode(nums.at(start));

		unsigned int rootIdx = start + size / 2;
		TreeNode* curr = new TreeNode(nums.at(rootIdx));
		curr->left  = sortedArrayToBSTImpl(nums, start, rootIdx);
		curr->right = sortedArrayToBSTImpl(nums, rootIdx+1, end);
		return curr;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBSTImpl(nums, 0, nums.size());
	}
};
