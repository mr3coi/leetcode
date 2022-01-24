class Solution {
public:
    /*
     * Time complexity: Omega(s.length())
     * Space complexity: Omega(1)
     */
    int firstUniqChar(string s) {
        constexpr size_t NUM_ALPHABET{26};
        vector<int> occurrence(NUM_ALPHABET, -1);
        for (int i=0; i<s.length(); ++i)
        {
            int alpha = static_cast<int>(s[i] - 'a');
            // Already observed at least once.
            if (occurrence[alpha] > -1)
            {
                occurrence[alpha] = -2;
            }
            // Never observed.
            else if (occurrence[alpha] == -1)
            {
                occurrence[alpha] = i;
            }
            // occurrence[alpha] == -2: already observed twice or more => ignore.
        }
        int pos{static_cast<int>(s.length())};
        for (int i=0; i<NUM_ALPHABET; ++i)
        {
            if (occurrence[i] >= 0 && occurrence[i] < pos)
            {
                pos = occurrence[i];
            }
        }
        return pos < static_cast<int>(s.length()) ? pos : -1;
    }
};
