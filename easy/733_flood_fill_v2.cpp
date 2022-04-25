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
        std::queue<std::pair<int, int>> q;
        q.emplace(sr, sc);
        int r{};
        int c{};
        int origColor{image[sr][sc]};
        while (!q.empty())
        {
            std::tie(r, c) = q.front();
            q.pop();
            if (!visited[r][c] && image[r][c] == origColor)
            {
                image[r][c] = newColor;
                visited[r][c] = true;
                if (r > 0)
                {
                    q.emplace(r - 1, c);
                }
                if (r < image.size() - 1)
                {
                    q.emplace(r + 1, c);
                }
                if (c > 0)
                {
                    q.emplace(r, c - 1);
                }
                if (c < image[0].size() - 1)
                {
                    q.emplace(r, c + 1);
                }
            }
        }
        return image;
    }
};
