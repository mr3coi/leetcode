class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    string reverseWords(string s) {
        std::vector<char> ret(s.begin(), s.end());
        int pos = 0;
        // Bypass leading spaces (as redundant measure)
        while (ret.at(pos) == ' ')
        {
            ++pos;
        }
        int currWordStart{pos};
        for (; pos < s.size(); ++pos)
        {
            if (ret.at(pos) == ' ')
            {
                std::reverse(ret.begin() + currWordStart, ret.begin() + pos);
                // Bypass spaces between words (as redundant measure)
                while (pos < s.size() && ret.at(pos) == ' ')
                {
                    ++pos;
                }
                currWordStart = pos;
            }

        }
        if (currWordStart < pos)
        {
            std::reverse(ret.begin() + currWordStart, ret.end());
        }
        return std::string(ret.begin(), ret.end());
    }
};
