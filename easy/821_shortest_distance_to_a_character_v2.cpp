class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<int> shortestToChar(string s, char c) {
        int prev{INT_MIN / 2};
        int i{0};
        std::vector<int> ret{};
        ret.reserve(s.size());
        for (int curr = 0; curr < s.size(); ++curr)
        {
            if (s[curr] != c)
            {
                continue;
            }
            for (; i <= curr; ++i)
            {
                ret.push_back(std::min(i - prev, curr - i));
            }
            prev = curr;
        }
        for (; i < s.size(); ++i)
        {
            ret.push_back(i - prev);
        }
        return ret;
    }
};
