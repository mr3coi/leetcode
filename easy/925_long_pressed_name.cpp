class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time Complexity: Theta(name.size() + typed.size())
    // Space complexity: Theta(1)
    bool isLongPressedName(string name, string typed)
    {
        int nIdx, tIdx;
        for (nIdx = 0, tIdx = 0; nIdx < name.size() && tIdx < typed.size(); )
        {
            char const n = name[nIdx];
            char const t = typed[tIdx];
            if (n != t)
            {
                return false;
            }
            int nCnt = 0;
            int tCnt = 0;

            // Count the consecutive occurrences of the char at the given location.
            while (nIdx < name.size() && name[nIdx] == n)
            {
                ++nCnt;
                ++nIdx;
            }
            while (tIdx < typed.size() && typed[tIdx] == t)
            {
                ++tCnt;
                ++tIdx;
            }
            if (nCnt > tCnt)
            {
                return false;
            }
        }
        // Should have reached the ends of both strings.
        return tIdx == typed.size() && nIdx == name.size();
    }
};
