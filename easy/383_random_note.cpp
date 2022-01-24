class Solution {
public:
    // Average/Worst-case time complexity: Omega(N_r + N_m),
    // where N_r: length of ransomNote, N_m: length of magazine
    //
    // Average/Worst-case space complexity: Omega(1),
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.length() < ransomNote.length())
        {
            return false;
        }

        auto charToIdx = [](char c) -> int {
            return static_cast<int>(c >= 'a' ? c - 'a' : c - 'A');
        };
        constexpr size_t NUM_ALPHABET = 26;
        vector<int> count(NUM_ALPHABET, 0);
        for (char c : magazine)
        {
            ++count[charToIdx(c)];
        }
        for (char c : ransomNote)
        {
            --count[charToIdx(c)];
        }
        for (size_t i=0; i<NUM_ALPHABET; ++i)
        {
            if (count[i] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
