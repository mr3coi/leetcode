class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int candIdx{-1};
        size_t candLen{INT_MAX};
        auto const chars = decompose(licensePlate);
        for (int i = 0; i < words.size(); ++i)
        {
            auto word = std::vector<char>(words.at(i).begin(), words.at(i).end());
            std::sort(word.begin(), word.end());
            size_t plateLoc{0};
            size_t wordLoc{0};
            while (plateLoc < chars.size() && wordLoc < word.size())
            {
                while (wordLoc < word.size() && chars.at(plateLoc) > word.at(wordLoc))
                {
                    ++wordLoc;
                }
                if (wordLoc >= word.size() || chars.at(plateLoc) < word.at(wordLoc))
                {
                    break;
                }
                ++plateLoc;
                ++wordLoc;
            }
            bool isMatch{plateLoc == chars.size()};
            if (isMatch && word.size() < candLen)
            {
                candLen = word.size();
                candIdx = i;
            }
        }
        return words.at(candIdx);
    }

    std::vector<char> decompose(std::string const& licensePlate)
    {
        std::vector<char> ret{};
        for (char c : licensePlate)
        {
            if (c >= 'a' && c <= 'z')
            {
                ret.push_back(c);
            }
            else if (c >= 'A' && c <= 'Z')
            {
                ret.push_back(c - 'A' + 'a');
            }
        }
        std::sort(ret.begin(), ret.end());
        return ret;
    }
};
