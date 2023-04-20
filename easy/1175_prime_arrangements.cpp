#define MOD 1000000007

class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int nbPrimesUpto(int n)
    {
        int ret{};
        for (int i = 2; i <= n; ++i)
        {
            bool success{true};
            for (int j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    success = false;
                    break;
                }
            }
            if (success)
            {
                ++ret;
            }
        }
        return ret;
    }

    long long permMod(int n)
    {
        long long ret{1};
        for (int i = 1; i <= n; ++i)
        {
            ret = (ret * i) % MOD;
        }
        return ret;
    }

    int numPrimeArrangements(int n)
    {
        int nbPrimes = nbPrimesUpto(n);
        auto ret = permMod(nbPrimes);
        ret *= permMod(n - nbPrimes);
        return static_cast<int>(ret % MOD);
    }
};
