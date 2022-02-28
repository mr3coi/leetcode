class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int fib(int n) {
        std::vector<int> fibs{0, 1};
        for (int i = 2; i <= n; ++i)
        {
            fibs.at(i % 2) += fibs.at(1 - i % 2);
        }
        return fibs.at(n % 2);
    }
};
