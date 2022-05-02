class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool backspaceCompare(string s, string t) {
        int sSkips{};
        int tSkips{};
        auto sIt = s.rbegin();
        auto tIt = t.rbegin();
        while (sIt != s.rend() && tIt != t.rend())
        {
            if (*sIt == '#')
            {
                ++sSkips;
                ++sIt;
                continue;
            }
            if (sSkips)
            {
                --sSkips;
                ++sIt;
                continue;
            }
            if (*tIt == '#')
            {
                ++tSkips;
                ++tIt;
                continue;
            }
            if (tSkips)
            {
                --tSkips;
                ++tIt;
                continue;
            }
            if (*sIt != *tIt)
            {
                return false;
            }
            ++sIt;
            ++tIt;
        }
        while (sIt != s.rend())
        {
            if (*sIt == '#')
            {
                ++sSkips;
                ++sIt;
                continue;
            }
            if (sSkips)
            {
                --sSkips;
                ++sIt;
                continue;
            }
            return false;
        }
        while (tIt != t.rend())
        {
            if (*tIt == '#')
            {
                ++tSkips;
                ++tIt;
                continue;
            }
            if (sSkips)
            {
                --tSkips;
                ++tIt;
                continue;
            }
            return false;
        }
        return true;
    }
};
