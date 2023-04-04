class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(#words)
    // Space complexity: Theta(text.size())
    vector<string> findOcurrences(string text, string first, string second)
    {
        std::istringstream iss{text};
        std::string token{};
        bool matchedFirst{};
        bool matchedSecond{};
        std::vector<std::string> ret{};

        while (iss >> token)
        {
            if (matchedSecond)
            {
                matchedSecond = false;
                ret.push_back(token);
            }
            if (matchedFirst)
            {
                matchedFirst = false;
                if (token == second)
                {
                    matchedSecond = true;
                    // The second token of a bigram can at the same time
                    // be the first token of the next bigram.
                    // Hence do not continue here.
                }
            }
            if (token == first)
            {
                matchedFirst = true;
            }
        }
        return ret;
    }
};
