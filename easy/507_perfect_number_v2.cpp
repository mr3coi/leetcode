class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool checkPerfectNumber(int num) {
        if (num == 1)
        {
            return false;
        }
        // Consider 1 separately here.
        int aggregate{1};
        // Process both ends simultaneously.
        // Only considering divisor >= 2 guarantees the value itself is not added to aggregate.
        for (int divisor = 2; divisor <= std::sqrt(num); ++divisor)
        {
            if (num % divisor == 0)
            {
                aggregate += divisor + num / divisor;
            }
        }
        return aggregate == num;
    }
};
