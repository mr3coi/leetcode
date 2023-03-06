// The farthest distance two repeating items can be from each other.
#define WINDOW_SIZE 4

class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(nums.size())
    // Space complexity: O(1)
    int repeatedNTimes(vector<int>& nums)
    {
        // Examine each window for repeated element.
        for (int i = 0; i < nums.size() - WINDOW_SIZE + 1; ++i)
        {
            // Constant-time loops within the given window.
            for (int j = i; j < i + WINDOW_SIZE - 1; ++j)
            {
                for (int k = j + 1; k < i + WINDOW_SIZE; ++k)
                {
                    if (nums[j] == nums[k])
                    {
                        return nums[j];
                    }
                }
            }
        }
        // Shouldn't arrive here.
        return -1;
    }
};
