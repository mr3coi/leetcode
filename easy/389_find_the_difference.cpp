class Solution {
public:
    /*
     * Time complexity: Omega(s.length() + t.length())
     * Space complexity: Omega(1)
     */
    char findTheDifference(string s, string t) {
        constexpr size_t ALPHABET{26};
        vector<int> countS(ALPHABET, 0), countT(ALPHABET, 0);
        for (char c : s)
        {
            ++countS[static_cast<int>(c - 'a')];
        }
        for (char c : t)
        {
            ++countT[static_cast<int>(c - 'a')];
        }
        for (int i=0; i<ALPHABET; ++i)
        {
            if (countT[i] > countS[i])
            {
                return 'a' + i;
            }
        }
        return 'a'; // Dummy return
    }
};
