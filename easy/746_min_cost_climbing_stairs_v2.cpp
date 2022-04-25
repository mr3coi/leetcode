class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size() + 1, -1);
        cache[cost.size()] = 0;
        cache[cost.size() - 1] = cost[cost.size() - 1];
        for (int i = static_cast<int>(cost.size()) - 2; i >= 0; --i)
        {
            cache[i] = cost[i] + std::min(cache[i+1], cache[i+2]);
        }
        return std::min(cache[0], cache[1]);
    }
};
