class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int binaryGap(int n) {
        // Base case: Power of 2 (only a single 1-bit) && 0
        if ((n & (n-1)) == 0)
        {
            return 0;
        }
        int currDist{INT_MIN}; // Helps ignore rightmost 0's
        int maxDist{-1};
        while (n)
        {
            if (n & 1)
            {
                maxDist = std::max(maxDist, currDist);
                currDist = 1;
            }
            else
            {
                ++currDist;
            }
            n >>= 1;
        }
        return maxDist;
    }
};
