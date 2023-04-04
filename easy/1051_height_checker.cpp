#define MAX_HEIGHT 100

class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(heights.size())
    // Space complexity: Theta(MAX_HEIGHT)
    int heightChecker(vector<int>& heights)
    {
        std::vector<int> count(MAX_HEIGHT + 1);
        for (int const height : heights)
        {
            ++count[height];
        }
        int ret{static_cast<int>(heights.size())};
        int curr{};
        for (int h = 1; h < MAX_HEIGHT + 1; ++h)
        {
            for (int i = 0; i < count[h]; ++i)
            {
                // Exclude each match case.
                if (heights[curr++] == h)
                {
                    --ret;
                }
            }
        }
        return ret;
    }
};
