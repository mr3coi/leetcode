class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    /*
     * Time complexity: O(nlog n)
     * Space complexity: O(1) if allows in-place, o/w Theta(n)
     */
    int findLHS(vector<int>& nums) {
        int ret{};
        std::sort(nums.begin(), nums.end());
        int last{std::numeric_limits<int>::min()};
        int curr{nums.at(0)};
        int lastCount{};
        int currCount{};
        auto const updateRet = [&] {
            if (last == curr - 1)
            {
                ret = std::max(ret, lastCount + currCount);
            }
        };
        for (int num : nums)
        {
            if (num == curr)
            {
                ++currCount;
            }
            else
            {
                updateRet();
                last = curr;
                lastCount = currCount;
                curr = num;
                currCount = 1;
            }
        }
        updateRet();
        return ret;
    }
};
