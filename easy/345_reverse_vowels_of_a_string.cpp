class Solution {
public:
    string reverseVowels(string s) {
        ostringstream ret;
        auto isVowel = [](char c) {
            return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')
                || (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
        };
        auto rIt = s.rbegin();
        auto nextVowel = [&]() {
            while (rIt != s.rend() && !isVowel(*rIt))
            {
                ++rIt;
            }
        };
        nextVowel();
        for (auto c : s)
        {
            if (isVowel(c))
            {
                ret << *(rIt++);
                nextVowel();
            }
            else
            {
                ret << c;
            }
        }
        return ret.str();
    }
};
