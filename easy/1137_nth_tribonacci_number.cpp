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
        if (!n)
        {
            return 0;
        }
        if (n <= 2)
        {
            return 1;
        }
        std::vector<int> cache(n + 1);
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            cache[i] = cache[i-3] + cache[i-2] + cache[i-1];
        }
        return cache[n];
    }
};
