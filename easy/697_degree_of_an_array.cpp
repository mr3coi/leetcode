class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

     int findShortestSubArray(vector<int>& nums) {
        // Find all modes
        vector<int> tmp(nums.begin(), nums.end());
        std::sort(tmp.begin(), tmp.end());
        std::vector<int> modes{};
        int curr{tmp[0]};
        int currCount{0};
        int modeCount{0};
        auto const update = [&]() {
            if (currCount > modeCount)
            {
                modes.clear();
                modes.push_back(curr);
                modeCount = currCount;
            }
            else if (currCount == modeCount)
            {
                modes.push_back(curr);
            }
        };
        for (int num : tmp)
        {
            if (num == curr)
            {
                ++currCount;
            }
            else
            {
                update();
                curr = num;
                currCount = 1;
            }
        }
        update();

        // Find the smallest subarray per mode.
        int ret{std::numeric_limits<int>::max()};
        for (auto const mode : modes)
        {
            int start{};
            int end{};
            for (auto it = nums.begin(); it != nums.end(); ++it)
            {
                if (*it == mode)
                {
                    start = it - nums.begin();
                    break;
                }
            }
            for (auto it = nums.rbegin(); it != nums.rend(); ++it)
            {
                if (*it == mode)
                {
                    end = nums.size() - 1 - (it - nums.rbegin());
                    break;
                }
            }
            ret = std::min(ret, end - start + 1);
        }
        return ret;
    }
};
