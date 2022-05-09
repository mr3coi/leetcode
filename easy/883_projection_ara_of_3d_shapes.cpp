class Solution {
    static int const GRID_LEN{50};

public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int projectionArea(vector<vector<int>>& grid) {
        int xArea{};
        int zArea{};
        std::vector<int> maxYHeights(GRID_LEN, 0);
        for (auto const& row : grid)
        {
            xArea += *std::max_element(row.begin(), row.end());
            for (int x = 0; x < row.size(); ++x)
            {
                maxYHeights.at(x) = std::max(maxYHeights.at(x), row.at(x));
                zArea += row.at(x) > 0;
            }
        }
        int yArea{std::accumulate(maxYHeights.begin(), maxYHeights.end(), 0)};
        return xArea + yArea + zArea;
    }
};
