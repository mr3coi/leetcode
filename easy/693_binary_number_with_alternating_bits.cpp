class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool hasAlternatingBits(int n) {
        for (unsigned int bit = 1 - n % 2; n > 0 && bit < 32; bit += 2)
        {
            n -= (1 << bit);
        }
        return n == 0;
        
    }
};
