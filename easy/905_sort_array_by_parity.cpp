class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    inline bool isEven(int val)
    {
        return val % 2 == 0;
    }

    // Time complexity: Theta(nums.size())
    // Space complexity: Theta(1)
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        if (nums.size() <= 1)
        {
            return nums;
        }
        int j{};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!isEven(nums[i]))
            {
                continue;
            }
            while (j < i && isEven(nums[j]))
            {
                ++j;
            }
            std::swap(nums[i], nums[j]);
        }
        return nums;
    }
};
