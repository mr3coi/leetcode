class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image)
        {
            for (size_t col = 0; col <= (row.size() + row.size() % 2) / 2; ++col)
            {
                swapInverted(row[col], row[row.size() - 1 - col]);
            }
        }
        return image;
    }

    void swapInverted(int& a, int& b)
    {
        int aInvertedCopy = 1 - a;
        a = 1 - b;
        b = aInvertedCopy;
    }
};
