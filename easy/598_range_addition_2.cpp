class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto const& op : ops)
        {
            m = std::min(m, op.at(0));
            n = std::min(n, op.at(1));
        }
        return m * n;
    }
};
