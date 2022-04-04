class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool validPalindrome(string s) {
        return isValid(s, 0, s.size() - 1, 1);
    }

    // End-inclusive
    bool isValid(string const& s, int start, int end, int nbIndulgences)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return nbIndulgences > 0 ?
                        isValid(s, start + 1, end, nbIndulgences-1)
                            || isValid(s, start, end - 1, nbIndulgences-1)
                        : false;
            }
            ++start;
            --end;
        }
        return true;
    }
};
