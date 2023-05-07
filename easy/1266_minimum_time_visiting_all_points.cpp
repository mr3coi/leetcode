class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points)
    {
        int ret{};
        for (auto from = points.begin(), to = points.begin() + 1;
             to != points.end() && from != points.end();
             ++to)
        {
            int nbXMoves = std::abs(from->at(0) - to->at(0));
            int nbYMoves = std::abs(from->at(1) - to->at(1));
            ret += std::max(nbXMoves, nbYMoves);
            from = to;
        }
        return ret;
    }
};
