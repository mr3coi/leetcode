class Solution {
public:
    static int const LINE_WIDTH{100};

    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<int> numberOfLines(vector<int>& widths, string s) {
        if (s.empty())
        {
            return {0, 0};
        }
        int nbLines{1};
        int soFar{};
        for (char c : s)
        {
            auto const& width = widths[c - 'a'];
            if (soFar + width > LINE_WIDTH)
            {
                soFar = 0;
                ++nbLines;
            }
            soFar += width;
        }
        return {nbLines, soFar};
    }
};
