class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // Lower-left triangle + diagonal
        for (int R = 0; R < matrix.size() - 1; ++R)
        {
            int const diagVal{matrix[R][0]};
            for (int r = R; r < matrix.size(); ++r)
            {
                if (r - R >= matrix[0].size())
                {
                    break;
                }
                if (matrix[r][r-R] != diagVal)
                {
                    return false;
                }
            }
        }

        // Upper-right triangle
        for (int C = 1; C < matrix[0].size() - 1; ++C)
        {
            int const diagVal{matrix[0][C]};
            for (int c = C; c < matrix[0].size(); ++c)
            {
                if (c - C >= matrix.size())
                {
                    break;
                }
                if (matrix[c-C][c] != diagVal)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
