class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(log n)
    // Space complexity: Theta(1)
    int bitwiseComplement(int n)
    {
        if (!n)
        {
            return 1;
        }
        int power{1};
        while (power <= n)
        {
            power *= 2;
        }
        return power - 1 - n;
    }
};
