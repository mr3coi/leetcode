class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity can be improved by scanning and looking for 3 maxs & 3 mins.
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        // Covers both all-negative & not-all-negative cases.
        // Maximum for when all numbers are positive/negative.
        int maxPositiveProd = nums.at(nums.size()-3) * nums.at(nums.size()-2) * nums.at(nums.size()-1);
        // Maximum for when there is a mixture of both.
        int maxNegativeProd = nums.at(0) * nums.at(1) * nums.at(nums.size()-1);
        return std::max(maxPositiveProd, maxNegativeProd);
    }
};
