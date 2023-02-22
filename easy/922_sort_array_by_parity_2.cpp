class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(nums.size())
    // Space complexity: Theta(1)
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int o{1};
        auto const update = [&nums, &o]
        {
            while (o < nums.size() && nums[o] % 2 == 1)
            {
                o += 2;
            }
        };
        update();
        for (int e = 0; e < nums.size(); e += 2)
        {
            if (nums[e] % 2 == 0)
            {
                continue;
            }
            // Protective measure
            // (Shouldn't be necessary as long as half the integers are even)
            if (o >= nums.size())
            {
                break;
            }
            std::swap(nums[e], nums[o]);
            o += 2;
            update();
        }
        return nums;
    }
};
