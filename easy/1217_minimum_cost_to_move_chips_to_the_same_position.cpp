class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int minCostToMoveChips(vector<int>& position)
    {
        int oddTotal{};
        for (auto p : position)
        {
            oddTotal += (p & 1);
        }
        return std::min(oddTotal, static_cast<int>(position.size()) - oddTotal);
    }
};
