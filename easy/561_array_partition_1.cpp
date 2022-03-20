class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int ret{};
        for (int i = 0; i < nums.size() / 2; ++i)
        {
            ret += nums.at(i * 2);
        }
        return ret;
    }
};
