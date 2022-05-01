class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        std::vector<std::string> tokens = process(std::move(paragraph));
        std::unordered_set bannedSet(banned.begin(), banned.end());

        std::unordered_map<std::string, int> counts{};
        for (auto const& token : tokens)
        {
            if (bannedSet.find(token) != bannedSet.end())
            {
                continue;
            }
            if (counts.find(token) == counts.end())
            {
                counts[token] = 1;
            }
            else
            {
                ++counts[token];
            }
        }

        int maxCount{-1};
        std::string ret{};
        for (auto const& kv : counts)
        {
            if (kv.second > maxCount)
            {
                ret = kv.first;
                maxCount = kv.second;
            }
        }
        return ret;
    }

    std::vector<std::string> process(std::string&& paragraph)
    {
        std::vector<std::string> tokens;
        std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
                [](char c) { return std::ispunct(c) ? ' ' : std::tolower(c); });
        std::string token;
        istringstream iss(paragraph);
        while (std::getline(iss, token, ' '))
        {
            if (!token.empty())
            {
                tokens.push_back(toLower(std::move(token)));
            }
        }
        return tokens;
    }
};
