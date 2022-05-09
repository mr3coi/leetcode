class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int const M = matrix.size();
        int const N = matrix.at(0).size();
        int const BS = 50; // Arbitrary choice
        std::vector<std::vector<int>> ret(N, std::vector<int>(M, 0));

        // Block-wise approach for better locality
        for (int bR = 0; bR < (M + BS) / BS; ++bR) // block row
        {
            for (int bC = 0; bC < (N + BS) / BS; ++bC) // block column
            {
                for (int r = 0; r < BS; ++r)
                {
                    int gR = bR * BS + r; // global row
                    if (gR >= M)
                    {
                        break;
                    }
                    for (int c = 0; c < BS; ++c)
                    {
                        int gC = bC * BS + c; // global column
                        if (gC >= N)
                        {
                            break;
                        }
                        ret.at(gC).at(gR) = matrix.at(gR).at(gC);
                    }
                }
            }
        }
        return ret;
    }
};
