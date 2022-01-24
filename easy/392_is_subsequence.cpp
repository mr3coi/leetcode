class Solution {
public:
    /*
     * Time complexity: Omega(t.length())
     * Space complexity: Omega(1)
     */
    bool isSubsequence(string s, string t) {
        if (s.length() == 0 || s == t)
        {
            return true;
        }
        for (size_t i_s=0, i_t=0; i_t < t.length(); ++i_t)
        {
            if (s[i_s] == t[i_t])
            {
                ++i_s;
            }
            if (i_s == s.length())
            {
                return true;
            }
        }
        return false;
    }
};
