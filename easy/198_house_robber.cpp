class Solution {
public:
	int robHelper(std::vector<int>& nums, std::vector<int>& cache, int start) {
		if (start >= nums.size()) return 0;
		if (cache[start] != -1) return cache[start];
		int& out = cache[start];
		out = nums[start];
		int maxNext = 0;
		for (int next=start+2; next<nums.size(); ++next) {
			int curr = robHelper(nums, cache, next);
			if (curr > maxNext) maxNext = curr;
		}
		out += maxNext;
		return out;
	}

	int rob(vector<int>& nums) {
		std::vector<int> cache(nums.size(), -1);
		int out = 0;
		for (int i=0; i<nums.size(); ++i) {
			out = std::max(out,  robHelper(nums, cache, i));
		}
		return out;
	}
};
