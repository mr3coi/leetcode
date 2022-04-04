class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen{0};
        int currLen{1};
        for (auto it = nums.begin() + 1; it != nums.end(); ++it)
        {
            if (*it > *(it-1))
            {
                ++currLen;
            }
            else
            {
                maxLen = std::max(maxLen, currLen);
                currLen = 1;
            }
        }
        return std::max(maxLen, currLen);
    }
};
