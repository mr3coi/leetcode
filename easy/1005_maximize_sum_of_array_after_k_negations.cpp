class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(nums.size() * log (nums.size()))
    // Space complexity: Theta(1)
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        auto posIt = std::lower_bound(nums.begin(), nums.end(), 0);
        bool const hasZero{*posIt == 0};
        int nbNegative = posIt - nums.begin();
        int nbNegate{-1}; //< Number of the first few elements to be negated.
        auto negate = [&nums](int nbNegate) {
            for (int i = 0; i < nbNegate; ++i)
            {
                nums[i] *= -1;
            }
        };
        if (nbNegative == 0)
        {
            // Keep negative the first element only.
            negate(k % 2);
        }
        else if (nbNegative > k)
        {
            // Negate the first k elements.
            negate(k);
        }
        else // 0 < nbNegative <= k
        {
            // Negate all negative elements, then negate
            // the smallest element.
            negate(nbNegative);
            if ((k - nbNegative) % 2 == 1)
            {
                if (posIt == nums.end())
                {
                    *nums.rbegin() *= -1;
                }
                else
                {
                    *(posIt - (*posIt >= *(posIt - 1))) *= -1;
                }
            }
        }
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};
