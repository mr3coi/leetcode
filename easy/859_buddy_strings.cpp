class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
        {
            return false;
        }
        char mismatchS{};
        char mismatchG{};
        bool chance{true};
        bool hasMultiple{false};
        std::vector<int> alphabet('z' - 'a' + 1, 0);

        for (size_t i = 0; i < s.size(); ++i)
        {
            hasMultiple = hasMultiple || (++alphabet[s[i] - 'a'] > 1);
            if (s[i] != goal[i])
            {
                // Already used one swap chance => false
                if (!chance)
                {
                    return false;
                }
                // Store first mismatch
                if (!mismatchS)
                {
                    mismatchS = s[i];
                    mismatchG = goal[i];
                }
                // Second mismatch
                else if (mismatchS != goal[i] || mismatchG != s[i])
                {
                    return false;
                }
                // Swap took place
                else
                {
                    chance = false;
                }
            }
        }
        // Only a single mismatch => false
        if (chance && mismatchS)
        {
            return false;
        }
        // If chance == true, then no mismatch => true if candidate exists
        return !chance || hasMultiple;
    }
};
