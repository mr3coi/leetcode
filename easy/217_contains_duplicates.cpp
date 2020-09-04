class Solution {
public:
	/**
	 * Inserts each element in num into an unordered set,
	 * and see if there is a collision (collision means duplicate)
	 */
	bool containsDuplicate(vector<int>& nums) {
		std::unordered_set<int> uniq;
		uniq.reserve(nums.size());
		for (int num : nums) {
			if (!uniq.insert(num).second) return true;
		}
		return false;
	}
};
