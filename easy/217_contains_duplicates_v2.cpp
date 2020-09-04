class Solution {
public:
	/**
	 * In-place approach to save memory,
	 * albeit at the cost of runtime.
	 * Sorts given array and checks for neighboring
	 * elements with the same value.
	 *
	 * Time:  O(n*log n)
	 * Space: O(1)
	 */
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() <= 1) return false;
		std::sort(nums.begin(), nums.end());
		for (int i=1; i<nums.size(); ++i) {
			if (nums[i] == nums[i-1]) return true;
		}
		return false;
	}
};
