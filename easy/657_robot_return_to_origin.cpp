class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool judgeCircle(string moves) {
        int lrCount{0};
        int udCount{0};
        for (char c : moves)
        {
            switch (c)
            {
            case 'U': ++udCount; break;
            case 'D': --udCount; break;
            case 'L': --lrCount; break;
            case 'R': ++lrCount; break;
            }
        }
        return !lrCount && !udCount;
    }
};
