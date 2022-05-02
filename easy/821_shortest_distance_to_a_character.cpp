class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<int> shortestToChar(string s, char c) {
        std::vector<int> locs{INT_MIN / 2};
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == c)
            {
                locs.push_back(i);
            }
        }
        locs.push_back(INT_MAX / 2);

        int ptr{1};
        std::vector<int> ret{};
        for (int i = 0; i < s.size(); ++i)
        {
            ret.push_back(std::min(i - locs.at(ptr-1), locs.at(ptr) - i));
            if (i == locs.at(ptr))
            {
                ++ptr;
            }
        }
        return ret;
    }
};
