class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cache(cost.size(), -1);
        return std::min(helper(cost, 0, cache), helper(cost, 1, cache));
    }

    // Returns the minimum cost to climb from curr to top.
    int helper(vector<int>& cost, int curr, vector<int>& cache)
    {
        if (curr >= cost.size())
        {
            return 0;
        }
        if (cache[curr] > -1)
        {
            return cache[curr];
        }
        auto ret =  cost[curr] + std::min(helper(cost, curr + 1, cache),
                helper(cost, curr + 2, cache));
        cache[curr] = ret;
        return ret;
    }
};
