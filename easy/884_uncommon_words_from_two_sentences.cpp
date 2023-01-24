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
        std::istringstream iss2(s2);
        std::string token;
        std::unordered_map<std::string, int> tokens1{};
        std::unordered_map<std::string, int> tokens2{};
        while (std::getline(iss1, token, ' '))
        {
            if (tokens1.find(token) == tokens1.end())
            {
                tokens1[token] = 1;
            }
            else
            {
                ++tokens1[token];
            }
        }
        while (std::getline(iss2, token, ' '))
        {
            if (tokens2.find(token) == tokens2.end())
            {
                tokens2[token] = 1;
            }
            else
            {
                ++tokens2[token];
            }
        }
        std::vector<std::string> ret{};
        for (auto const& kv : tokens1)
        {
            if (kv.second == 1 && tokens2.find(kv.first) == tokens2.end())
            {
                ret.push_back(kv.first);
            }
        }
        for (auto const& kv : tokens2)
        {
            if (kv.second == 1 && tokens1.find(kv.first) == tokens1.end())
            {
                ret.push_back(kv.first);
            }
        }
        return ret;
    }
};
