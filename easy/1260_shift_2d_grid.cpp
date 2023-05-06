class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        int const R = grid.size();
        int const C = grid[0].size();
        k %= R * C;
        if (!k)
        {
            return grid;
        }
        vector<vector<int>> ret(R, std::vector<int>(C));
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                int const dst = (i * C + j + k) % (R * C);
                ret[dst / C][dst % C] = grid[i][j];
            }
        }
        return ret;
    }
};
