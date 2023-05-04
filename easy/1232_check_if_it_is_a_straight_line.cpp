class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        // Shift to pass origin.
        for (int i = 1; i < coordinates.size(); ++i)
        {
            coordinates[i][0] -= coordinates[0][0];
            coordinates[i][1] -= coordinates[0][1];
        }
        for (int i = 2; i < coordinates.size(); ++i)
        {
            // All points should have the same slope as (x1,y1) w.r.t. origin.
            if (coordinates[i][0] * coordinates[1][1]
                    != coordinates[i][1] * coordinates[1][0])
            {
                return false;
            }
        }
        return true;
    }
};
