class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Assumes target.size() % divisor.size() == 0.
    // Time complexity: O(target.size())
    bool isDivisor(std::string const& target, std::string const& divisor)
    {
        int const divisorLen = divisor.size();
        for (int i = 0; i < target.size(); ++i)
        {
            if (target[i] != divisor[i % divisorLen])
            {
                return false;
            }
        }
        return true;
    }

    // Time complexity: O(gcd(L1,L2) * (L1 + L2))
    //                  where LX = strX.size(), X = 1,2
    // Space complexity: O(gcd(L1,L2)) ignoring call stack size.
    string gcdOfStrings(string str1, string str2)
    {
        int const largestCandSize = std::gcd(
                std::max(str1.size(), str2.size()),
                std::min(str1.size(), str2.size())
        );
        for (int candSize = largestCandSize; candSize > 0; --candSize)
        {
            if (largestCandSize % candSize)
            {
                // Cannot be the size of a common divisor.
                continue;
            }
            std::string const cand = str1.substr(0, candSize);
            if (isDivisor(str1, cand) && isDivisor(str2, cand))
            {
                return cand;
            }
        }
        return "";
    }
};
