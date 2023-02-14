class Solution {
public:
    // Time complexity: Theta(R*C)
    // Space complexity: Theta(1)
    int surfaceArea(vector<vector<int>>& grid)
    {
        int ret{};

        // grid is R x C
        int const R = grid.size();
        int const C = grid[0].size();

        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                // Top & bottom
                ret += 2 * (grid[r][c] > 0);
                
                // Sides
                for (int offset : {-1, 1})
                {
                    ret += (r + offset < 0 || r + offset >= R
                            ? grid[r][c]
                            : std::max(grid[r][c] - grid[r+offset][c], 0));
                    ret += (c + offset < 0 || c + offset >= C
                            ? grid[r][c]
                            : std::max(grid[r][c] - grid[r][c+offset], 0));
                }
            }
        }
        return ret;
    }
};
