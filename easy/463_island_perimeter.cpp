class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        auto const countShore = [&grid](int r, int c) {
            int nbLand{};
            nbLand += r > 0 ? grid[r-1][c] : 0;
            nbLand += r < grid.size()-1 ? grid[r+1][c] : 0;
            nbLand += c > 0 ? grid[r][c-1] : 0;
            nbLand += c < grid[0].size()-1 ? grid[r][c+1] : 0;
            return 4 - nbLand;
        };
        int ret{};
        for (int r = 0; r < grid.size(); ++r)
        {
            for (int c = 0; c < grid[0].size(); ++c)
            {
                if (grid[r][c])
                {
                    ret += countShore(r, c);
                }
            }
        }
        return ret;
    }
};
