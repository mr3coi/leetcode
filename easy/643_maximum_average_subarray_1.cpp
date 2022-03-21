class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    double findMaxAverage(vector<int>& nums, int k) {
        int currSum{};
        for (int i = 0; i < k; ++i)
        {
            currSum += nums.at(i);
        }
        int maxSum{currSum};
        for (int i = k; i < nums.size(); ++i)
        {
            currSum += nums.at(i) - nums.at(i-k);
            maxSum = std::max(maxSum, currSum);
        }
        return static_cast<double>(maxSum) / k;
    }
};
