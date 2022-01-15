/* O(n) approach, Kedane's algorithm */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return std::numeric_limits<int>::min();

		int mostRecentMax = -1;
		int output = std::numeric_limits<int>::min();
		for (int num : nums) {
			mostRecentMax = std::max(mostRecentMax, 0) + num;
			output = std::max(output, mostRecentMax);
		}
		return output;
    }
};
