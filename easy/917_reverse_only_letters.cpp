class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    static bool isAlpha(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    string reverseOnlyLetters(string s)
    {
        std::ostringstream o;
        auto rIt = s.rbegin();
        auto update = [&rIt, &s] {
            while (rIt != s.rend() && !isAlpha(*rIt))
            {
                ++rIt;
            }
        };
        update();
        for (char c : s)
        {
            o << (isAlpha(c) ? *rIt++ : c);
            update();
        }
        return o.str();
    }
};
