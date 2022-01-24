class Solution {
public:
    /*
     * Time complexity: Omega(s.length() + t.length())
     * Space complexity: Omega(1)
     */
    char findTheDifference(string s, string t) {
        size_t sum{};
        for (char c : t)
        {
            sum += static_cast<size_t>(c);
        }
        for (char c : s)
        {
            sum -= static_cast<size_t>(c);
        }
        return static_cast<char>(sum);
    }
};
