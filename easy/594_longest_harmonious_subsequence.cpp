class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    /*
     * Time complexity: O(nums.size())
     * Space complexity: O(nums.size())
     */
    int findLHS(vector<int>& nums) {
        std::map<int, int> counts;
        for (int num : nums)
        {
            if (counts.find(num) == counts.end())
            {
                counts[num] = 0;
            }
            ++counts[num];
        }
        int maxLen{};
        auto getCountElseZero = [&counts](int const num) {
            auto const it = counts.find(num);
            return it != counts.end() ? it->second : 0;
        };
        for (auto const& kv : counts)
        {
            int const oneLargeCount{getCountElseZero(kv.first + 1)};
            if (oneLargeCount == 0)
            {
                continue;
            }
            maxLen = std::max(maxLen, oneLargeCount + kv.second);
        }
        return maxLen;
    }
};
