class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int tribonacci(int n)
    {
        std::array<int, 4> cache = {0, 1, 1, 2};
        for (int i = 4; i <= n; ++i)
        {
            if (i % 4 == 0)
            {
                cache[0] = cache[1] + cache[2] + cache[3];
            }
            else if (i % 4 == 1)
            {
                cache[1] = cache[2] + cache[3] + cache[0];
            }
            else if (i % 4 == 2)
            {
                cache[2] = cache[3] + cache[0] + cache[1];
            }
            else
            {
                cache[3] = cache[0] + cache[1] + cache[2];
            }
        }
        return cache[n % 4];
    }
};
