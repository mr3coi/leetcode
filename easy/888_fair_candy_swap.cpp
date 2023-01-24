class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes)
    {
        auto const aliceTotal = std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        auto const bobTotal = std::accumulate(bobSizes.begin(), bobSizes.end(), 0);
        // Sort in ascending order.
        std::sort(aliceSizes.begin(), aliceSizes.end(), std::less());
        std::sort(bobSizes.begin(), bobSizes.end(), std::less());
        std::vector<int> ret{};
        for (auto const aBox : aliceSizes)
        {
            auto const target = aBox - (aliceTotal - bobTotal) / 2;
            auto const it = std::lower_bound(bobSizes.begin(), bobSizes.end(), target);
            if (it != bobSizes.end() && *it == target)
            {
                ret.push_back(aBox);
                ret.push_back(target);
                break;
            }
        }
        return ret;
    }
};
