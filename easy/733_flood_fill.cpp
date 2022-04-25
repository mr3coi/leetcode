class Solution {
public:
    using Grid = vector<vector<int>>;
    using VisitGrid = vector<vector<bool>>;

    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    Grid floodFill(Grid& image, int sr, int sc, int newColor)
    {
        VisitGrid visited(image.size(), vector<bool>(image[0].size(), false));
        helper(image, visited, sr, sc, image[sr][sc], newColor);
        return image;
    }

    void helper(Grid& g, VisitGrid& vg, int sr, int sc, int origColor, int newColor)
    {
        if (vg[sr][sc] || g[sr][sc] != origColor)
        {
            return;
        }
        g[sr][sc] = newColor;
        vg[sr][sc] = true;
        if (sr > 0)
        {
            helper(g, vg, sr - 1, sc, origColor, newColor);
        }
        if (sr < g.size() - 1)
        {
            helper(g, vg, sr + 1, sc, origColor, newColor);
        }
        if (sc > 0)
        {
            helper(g, vg, sr, sc - 1, origColor, newColor);
        }
        if (sc < g[0].size() - 1)
        {
            helper(g, vg, sr, sc + 1, origColor, newColor);
        }
    }
};
