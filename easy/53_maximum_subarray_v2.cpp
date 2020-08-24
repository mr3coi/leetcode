/* Divide-and-Conquer approach, O(nlog n) */
class Solution {
public:
	int maxSubArrayHelper(const vector<int>& nums, int start, int end) {
		if (start == end) return 0;
		if (end-start == 1) return nums.at(start);
		int mid = start + (end-start)/2;
		int maxSumL = std::numeric_limits<int>::min(), sum = 0;
		for (int i=mid-1;i>=start;--i) {
			sum += nums.at(i);
			maxSumL = std::max(maxSumL, sum);
		}
		int maxSumR = std::numeric_limits<int>::min();
		sum = 0;
		for (int i=mid; i<end; ++i) {
			sum += nums.at(i);
			maxSumR = std::max(maxSumR, sum);
		}
		return std::max(
				std::max(maxSumL+maxSumR, maxSubArrayHelper(nums,start,mid)),
				maxSubArrayHelper(nums,mid,end)
				);
	}

	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return std::numeric_limits<int>::min();
		return maxSubArrayHelper(nums, 0, nums.size());
	}
};
