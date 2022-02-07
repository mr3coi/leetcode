class Solution {
public:
    /*
     * Time complexity: Omega(s.length() + 26*2)
     * Space complexity: Omega(26*2)
     */
    int longestPalindrome(string s) {
        auto charToIdx = [](char c) -> int {
            return c >= 'a' ? c - 'a' + 'Z' - 'A' + 1 : c - 'A';
        };
        vector<int> charCount(26 * 2);
        for (char c : s)
        {
            ++charCount[charToIdx(c)];
        }
        int palLen{0};
        for (int count : charCount)
        {
            palLen += (count / 2) * 2 ;
        }
        return palLen + static_cast<int>(s.length() - palLen > 0);
    }
};
