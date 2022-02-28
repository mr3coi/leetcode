class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int sumOfPowers(int base, int exp)
    {
        double ret{std::pow(static_cast<double>(base), static_cast<double>(exp))};
        return static_cast<int>((static_cast<long long>(ret - 1) / (base - 1)));
    }

    bool checkPerfectNumber(int num) {
        // Prime factorization
        std::map<int, int> primeDivisors;
        int numCpy{num};
        int divisor = 2;
        while (numCpy > 1)
        {
            if (numCpy % divisor == 0)
            {
                if (primeDivisors.find(divisor) == primeDivisors.end())
                {
                    primeDivisors[divisor] = 0;
                }
                ++primeDivisors[divisor];
                numCpy /= divisor;
            }
            else
            {
                ++divisor;
            }
        }
        // Calculate aggregate
        // NOTE: Sum of all divisors == (1 + 2 + 2^2 + ... + 2^k) * (1 + 3 + ... ) * ...
        int aggregate{1};
        for (auto const& kv : primeDivisors)
        {
            aggregate *= sumOfPowers(kv.first, kv.second+1);
        }
        return aggregate == num * 2;
    }
};
