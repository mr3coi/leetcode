class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<vector<int>> largeGroupPositions(string s) {
        std::vector<std::vector<int>> ret{};
        char curr{s[0]};
        int start{0};
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != curr)
            {
                if (i - start >= 3)
                {
                    ret.emplace_back(std::initializer_list<int>{start, i-1});
                }
                curr = s[i];
                start = i;
            }
        }
        if (s.size() - start >= 3)
        {
            ret.emplace_back(
                std::initializer_list<int>{start, static_cast<int>(s.size()) - 1});
        }
        return ret;
    }
};
