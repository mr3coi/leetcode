class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(s.size())
    // Space complexity: Theta(1)
    vector<int> diStringMatch(string s)
    {
        int const n = s.size();
        int nextIncrease{1};
        int nextDecrease{-1};
        int min{};
        int max{};
        std::vector<int> ret;
        ret.reserve(n + 1);
        ret.push_back(0);
        // Assign values ignoring the [0,n] range for now.
        // The max/min of the permutation will always be at the end.
        for (auto const c : s)
        {
            if (c == 'I')
            {
                max = nextIncrease;
                ret.push_back(nextIncrease++);
            }
            else
            {
                min = nextDecrease;
                ret.push_back(nextDecrease--);
            }
        }
        // Shift all values so that they fall in [0,n] range.
        if (min < 0)
        {
            for (auto& val : ret)
            {
                val -= min;
            }
        }
        if (max > n)
        {
            for (auto& val : ret)
            {
                val -= (max - n);
            }
        }
        return ret;
    }
};
