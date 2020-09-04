class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		std::unordered_set<int> uniq;
		uniq.reserve(k);
		for (int i=0; i<nums.size(); ++i) {
			if (!uniq.insert(nums[i]).second) return true;
			if (i-k >= 0) uniq.erase(nums[i-k]);
		}
		return false;
	}
};
