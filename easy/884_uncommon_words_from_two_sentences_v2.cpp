class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<string> uncommonFromSentences(string s1, string s2)
    {
        std::istringstream iss1(s1);
        std::string token;
        std::unordered_map<std::string, int> tokens{};
        // std::istream::operator>> delimits on whitespaces by default.
        while (iss1 >> token)
        {
            // std::unordered_map::operator[] does value initialization (i.e. 0 in this case)
            // when the given key is missing.
            ++tokens[token];
        }
        iss1.clear();
        std::istringstream iss2(s2);
        while (iss2 >> token)
        {
            ++tokens[token];
        }
        iss2.clear();
        std::vector<std::string> ret{};
        for (auto const& kv : tokens)
        {
            if (kv.second == 1)
            {
                ret.push_back(kv.first);
            }
        }
        return ret;
    }
};
