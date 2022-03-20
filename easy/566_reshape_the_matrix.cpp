class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int const M{static_cast<int>(mat.size())};
        int const N{static_cast<int>(mat.at(0).size())};
        if (M * N != r * c)
        {
            return mat;
        }
        std::vector<std::vector<int>> ret(M * N / c, std::vector<int>(c));
        for (int m = 0; m < M; ++m)
        {
            for (int n = 0; n < N; ++n)
            {
                int const idx = m * N + n;
                int const row = idx / c;
                int const col = idx % c;
                ret.at(row).at(col) = mat.at(m).at(n);
            }
        }
        return ret;
    }
};
