class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int countBinarySubstrings(string s)
    {
        int ret{0};
        int start{0};
        int boundary{1};
        // Set up the first round.
        while (boundary < s.size() && s[boundary] == s[start])
        {
            ++boundary;
        }
        while (boundary < s.size())
        {
            int end = boundary;
            while (end < s.size() && s[end] == '1' - s[start])
            {
                ++end;
            }
            ret += std::min(boundary - start, end - boundary);
            start = boundary;
            boundary = end;
        }
        return ret;
    }
};
