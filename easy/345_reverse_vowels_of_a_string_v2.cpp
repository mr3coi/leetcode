class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c) {
            return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')
                || (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
        };
        auto start = s.begin();
        auto end = s.rbegin();
        // A hack to avoid rewriting the whole function to use indices instead of iterators.
        auto less = [&]() {
            return distance(s.begin(), start) < s.length() - 1 - distance(s.rbegin(), end);
        };
        while (1)
        {
            while (start != s.end() && !isVowel(*start))
            {
                ++start;
            }
            while (end != s.rend() && !isVowel(*end))
            {
                ++end;
            }
            if (start != s.end() && end != s.rend() && less())
            {
                std::swap(*start, *end);
                ++start;
                ++end;
            }
            else
            {
                break;
            }
        }
        return s;
    }
};
