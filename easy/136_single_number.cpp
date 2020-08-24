class Solution {
public:
	int singleNumber(vector<int>& nums) {
		std::unordered_set<int> uniq(nums.begin(), nums.end());
		long long uniqSum = 0;
		for (auto it = uniq.begin(); it != uniq.end(); ++it) uniqSum += static_cast<long long>(*it);
		long long rawSum = 0;
		for (int num : nums) rawSum += static_cast<long long>(num);
		return static_cast<int>(uniqSum * 2 - rawSum);
	}
};
