class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<std::string, char> map;
        bool occupied[26] = {0};
        unsigned int ptr = 0;
        std::stringstream ss(s);
        std::string buffer;
        while (getline(ss, buffer, ' '))
        {
            if (ptr >= pattern.length())
            {
                return false;
            }
            char currChar = pattern[ptr++];
            if (map.find(buffer) == map.end())
            {
                if (occupied[static_cast<int>(currChar-'a')])
                {
                    return false;
                }
                map[buffer] = currChar;
                occupied[static_cast<int>(currChar-'a')] = true;
            }
            else if (map[buffer] != currChar)
            {
                return false;
            }
        }
        return ptr == pattern.length();
    }
};
