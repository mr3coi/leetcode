class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(s.size())
    // Space complexity: Theta(1)
    int balancedStringSplit(string const& s)
    {
        int count{};
        int ret{};
        for (auto const c : s)
        {
            count += (c == 'L') * 2 - 1;
            if (!count)
            {
                // Take a greedy approach.
                ++ret;
            }
        }
        return ret;
    }
};
