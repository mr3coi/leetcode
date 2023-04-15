class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int numEquivDominoPairs(vector<vector<int>>& dominoes)
    {
        std::array<int, 100> counts = {0};
        for (auto const& domino : dominoes)
        {
            int const key = std::min(
                    domino[0] * 10 + domino[1],
                    domino[1] * 10 + domino[0]
                    );
            ++counts[key];
        }
        int ret{};
        for (int i = 11; i < 100; ++i)
        {
            ret += counts[i] * (counts[i] - 1) / 2;
        }
        return ret;
    }
};
