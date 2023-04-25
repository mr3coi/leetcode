class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    
    static inline int charIdx(char c)
    {
        return static_cast<int>(c - 'a');
    }

    int maxNumberOfBalloons(string text)
    {
        std::array<int, 26> counts = { 0 };
        for (char c : text)
        {
            ++counts[charIdx(c)];
        }
        for (char c : {'l', 'o'})
        {
            counts[charIdx(c)] /= 2;
        }
        int ret{static_cast<int>(text.size())};
        for (char c : {'b', 'a', 'l', 'o', 'n'})
        {
            ret = std::min(ret, counts[charIdx(c)]);
        }
        return ret;
    }
};
