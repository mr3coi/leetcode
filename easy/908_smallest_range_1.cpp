class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int smallestRangeI(vector<int>& nums, int k)
    {
        auto const min = *std::min_element(nums.begin(), nums.end());
        auto const max = *std::max_element(nums.begin(), nums.end());
        return std::max(max - min - 2 * k, 0);
    }
};
