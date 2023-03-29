class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool isBoomerang(vector<vector<int>>& points)
    {
        int x01 = points[1][0] - points[0][0];
        int y01 = points[1][1] - points[0][1];
        int x12 = points[2][0] - points[1][0];
        int y12 = points[2][1] - points[1][1];
        return y01 * x12 != x01 * y12;
    }
};
