class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(nums.size())
    // Space complexity: Theta(1)
    vector<bool> prefixesDivBy5(vector<int>& nums)
    {
        int decimal{};
        std::vector<bool> ret{};
        for (int const num : nums)
        {
            decimal *= 2;
            decimal += num;
            // No need to keep the multiple of 5, as that part
            // will continue to be multiple of 5 as iterations continue.
            // This way we can avoid overflow in `decimal`.
            decimal %= 5;
            ret.push_back(!decimal);
        }
        return ret;
    }
};
