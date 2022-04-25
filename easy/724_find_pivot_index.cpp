class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int pivotIndex(vector<int>& nums) {
        int const sum = std::accumulate(nums.begin(), nums.end(), 0);
        int leftSum{};
        for (int idx = 0; idx < nums.size(); ++idx)
        {
            int const sumMinusPivot{sum - nums.at(idx)};
            if (sumMinusPivot % 2 == 0 && leftSum == sumMinusPivot / 2)
            {
                return idx;
            }
            leftSum += nums.at(idx);
        }
        return -1;
    }
};
