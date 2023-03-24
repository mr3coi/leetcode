class Solution
{
public:
    using ReturnType = std::vector<std::vector<int>>;
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(rows + cols)
    // Space complexity: Theta(1) excluding output
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        ReturnType ret{};
        ret.reserve(rows * cols);
        int dist{};
        while (helper(rCenter, cCenter, dist, rows, cols, ret))
        {
            ++dist;
        }
        return ret;
    }

    // Add all valid points within the diamond defined by dist.
    // Returns true if at least one coordinate has been added to the output.
    // Time complexity: Theta(dist)
    // Space complexity: Theta(1)
    bool helper(int r, int c, int dist, int R, int C, ReturnType& ret)
    {
        bool updated{false};
        auto const update = [&](int rCurr, int cCurr) {
            if (rCurr >= 0 && rCurr < R && cCurr >= 0 && cCurr < C)
            {
                ret.push_back({rCurr, cCurr});
                updated = true;
            }
        };
        // Process the upper half of the diamond.
        r += dist;
        update(r, c);
        for (int o = 1; o <= dist; ++o)
        {
            update(r-o, c-o);
            update(r-o, c+o);
        }
        // Process the lower half of the diamond.
        r -= dist * 2;
        // If dist == 0, top of diamond == bottom of diamond.
        if (dist)
        {
            update(r, c);
        }
        // Exclude horizontal end-points this time.
        for (int o = 1; o < dist; ++o)
        {
            update(r+o, c-o);
            update(r+o, c+o);
        }
        return updated;
    }
};
