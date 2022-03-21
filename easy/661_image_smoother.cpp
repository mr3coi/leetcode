class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        std::vector<std::vector<int>> ret(img.size(), vector<int>(img.at(0).size()));
        for (int r = 0; r < img.size(); ++r)
        {
            for (int c = 0; c < img.at(0).size(); ++c)
            {
                int count{0};
                for (int i = r - 1; i <= r + 1; ++i)
                {
                    for (int j = c - 1; j <= c + 1; ++j)
                    {
                        if (i >= 0 && i < img.size() && j >= 0 && j < img.at(0).size())
                        {
                            ret.at(r).at(c) += img.at(i).at(j);
                            ++count;
                        }
                    }
                }
                ret.at(r).at(c) /= count;
            }
        }
        return ret;
    }
};
