class Solution {
public:
    string toGoatLatin(string sentence) {
        std::istringstream iss(sentence);
        std::string token{};
        std::ostringstream oss{};
        int tokenCount{};
        while(std::getline(iss, token, ' '))
        {
            if (tokenCount)
            {
                oss << ' ';
            }
            ++tokenCount;
            if (VOWELS.find(token[0]) == VOWELS.end())
            {
                char start = token[0];
                token.erase(0, 1);
                oss << token;
                oss << start;
            }
            else
            {
                oss << token;
            }

            oss << "ma";
            for (int i = 0; i < tokenCount; ++i)
            {
                oss << 'a';
            }
        }
        return oss.str();
    }
private:
    static std::unordered_set<char> const VOWELS;
};

std::unordered_set<char> const Solution::VOWELS = {'a', 'e', 'i', 'o', 'u'};
