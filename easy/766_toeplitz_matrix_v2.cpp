class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int r = 1; r < matrix.size(); ++r)
        {
            for (int c = 1; c < matrix[0].size(); ++c)
            {
                if (matrix[r][c] != matrix[r-1][c-1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
