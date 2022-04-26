class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int numJewelsInStones(string jewels, string stones) {
        std::vector<char> js(jewels.begin(), jewels.end());
        std::vector<char> sts(stones.begin(), stones.end());
        // Sort both lists in ascending order.
        std::sort(js.begin(), js.end());
        std::sort(sts.begin(), sts.end());
        auto jIt = js.begin();
        auto stIt = sts.begin();
        int ret{};
        while (jIt != js.end() && stIt != sts.end())
        {
            if (*jIt < *stIt)
            {
                ++jIt;
            }
            else if (*jIt > *stIt)
            {
                ++stIt;
            }
            else
            {
                ++ret;
                ++stIt;
            }
        }
        return ret;
    }
};
