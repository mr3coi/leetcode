class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(indices.size() + m * n)
    // Space complexity: Theta(m + n)
    int oddCells(int m, int n, vector<vector<int>>& indices)
    {
        std::vector<int> rowIncrements(m);
        std::vector<int> colIncrements(n);
        for (auto const& idx : indices)
        {
            ++rowIncrements[idx[0]];
            ++colIncrements[idx[1]];
        }
        int ret{};
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ret += (rowIncrements[i] + colIncrements[j]) & 1;
            }
        }
        return ret;
    }
};
