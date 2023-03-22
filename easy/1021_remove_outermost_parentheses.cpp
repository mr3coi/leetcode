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
    // Space complexity: Theta(1) excluding output
    string removeOuterParentheses(string const& s)
    {
        int openCount{};
        std::ostringstream o;
        for (char const c : s)
        {
            if (c == '(')
            {
                if (openCount)
                {
                    o << c;
                }
                ++openCount;
            }
            else // ')'
            {
                if (--openCount)
                {
                    o << c;
                }
            }
        }
        return o.str();
    }
};
