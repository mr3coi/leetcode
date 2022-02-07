class Solution {
public:
    /*
     * Time complexity: Omega(s.length() + 26*2)
     * Space complexity: O(1)
     */
    int longestPalindrome(string s) {
        unordered_map<char, int> charCount;
        for (char c : s)
        {
            charCount[c] = charCount.find(c) != charCount.end() ? 
                            charCount[c] + 1 : 1;
        }
        int palLen{0};
        for (char c = 'a'; c <= 'z'; ++c)
        {
            palLen += (charCount[c] / 2) * 2 ;
        }
        for (char c = 'A'; c <= 'Z'; ++c)
        {
            palLen += (charCount[c] / 2) * 2 ;
        }
        return palLen + static_cast<int>(s.length() - palLen > 0);
    }
};
