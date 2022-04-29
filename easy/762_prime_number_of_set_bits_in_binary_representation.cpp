class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int countPrimeSetBits(int left, int right) {
        int ret{};
        std::vector<bool> isPrime{32, false};
        for (int i : {2, 3, 5, 7, 11, 13, 17, 19})
        {
            isPrime[i] = true;
        }
        for (int val = left; val <= right; ++val)
        {
            int const nbBits{getNbBitsSet(val)};
            ret += isPrime[nbBits];
        }
        return ret;
    }

private:
    int getNbBitsSet(int val)
    {
        int ret{};
        while (val)
        {
            ret += val & 1;
            val >>= 1;
        }
        return ret;
    }

    bool isPrime(int const val)
    {
        if (val == 1)
        {
            return false;
        }
        int divisor = 2;
        while (divisor * divisor <= val)
        {
            if (val % divisor == 0)
            {
                return false;
            }
            ++divisor;
        }
        return true;
    }
};
