class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(n^2)
    // Space complexity: Theta(n)
    bool divisorGame(int n)
    {
        std::vector<int> cache(n + 1, false);
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
                if (i % j)
                {
                    continue;
                }
                if (!cache[i - j])
                {
                    // There is at least once scenario where Bob loses.
                    cache[i] = true;
                    break;
                }
            }
        }
        return cache[n];
    }
};
