class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool checkRecord(string s) {
        if (s.size() <= 1)
        {
            return true;
        }
        int absCount{};
        int lateStreak{};
        for (char c : s)
        {
            absCount += (c == 'A');
            if (absCount >= 2)
            {
                return false;
            }
            if (c == 'L')
            {
                ++lateStreak;
            }
            else
            {
                lateStreak = 0;
            }
            if (lateStreak >= 3)
            {
                return false;
            }
        }
        return true;
    }
};
