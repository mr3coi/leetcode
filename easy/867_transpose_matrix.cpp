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
        std::vector<std::vector<int>> ret(N, std::vector<int>(M, 0));
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                ret.at(j).at(i) = matrix.at(i).at(j);
            }
        }
        return ret;
    }
};
