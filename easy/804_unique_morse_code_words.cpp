class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    static std::vector<std::string> const alphabet;

    int uniqueMorseRepresentations(vector<string>& words) {
        std::unordered_set<std::string> uniqueRepresentations{};
        for (auto const& word : words)
        {
            std::ostringstream oss{};
            for (auto c : word)
            {
                oss << alphabet[c - 'a'];
            }
            uniqueRepresentations.insert(oss.str());
        }
        return uniqueRepresentations.size();
    }
};

std::vector<std::string> const Solution::alphabet = {
    ".-","-...","-.-.","-..",".",
    "..-.","--.","....","..",".---",
    "-.-",".-..","--","-.","---",".--.",
    "--.-",".-.","...","-","..-","...-",
    ".--","-..-","-.--","--.."};
