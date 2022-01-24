class Solution {
public:
    /*
     * Time complexity: Omega(s.length())
     * Space complexity: Omega(s.length())
     */
    int firstUniqChar(string s) {
        constexpr size_t NUM_ALPHABET{26};
        vector<vector<size_t>> occurrence(NUM_ALPHABET, vector<size_t>());
        for (size_t i=0; i<s.length(); ++i)
        {
            occurrence[static_cast<int>(s[i] - 'a')].push_back(i);
        }
        size_t pos{s.length()};
        for (auto o : occurrence)
        {
            if (o.size() == 1 && o[0] < pos)
            {
                pos = o[0];
            }
        }
        return pos < s.length() ? static_cast<int>(pos) : -1;
    }
};
