/* O(n) approach */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return std::numeric_limits<int>::min();
		int last = 0;
		int minSoFar = last, output = last, minNonPos = std::numeric_limits<int>::min();;
		for (int& num : nums) {
			if (num <= 0) minNonPos = std::max(minNonPos, num);
			num += last;
			minSoFar = std::min(minSoFar, num);
			output = std::max(output, num-minSoFar);
			last = num;
		}
		return output ? output : minNonPos;
    }
};
