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
    // Space complexity: Theta(1)
    vector<int> sortedSquares(vector<int> const& nums)
    {
        std::vector<int> ret;
        ret.reserve(nums.size());

        // Find the first non-negative element.
        auto pos = std::lower_bound(nums.begin(), nums.end(), 0);
        int const posIdx = pos - nums.begin();
        // Find the last negative element
        // (i.e. the negative element w/ the smallest abs. value).
        auto neg = nums.rbegin() + nums.size() - posIdx;
        while (pos != nums.end() && neg != nums.rend())
        {
            if (*pos <= -1 * *neg)
            {
                ret.push_back(*pos * *pos);
                ++pos;
            }
            else
            {
                ret.push_back(*neg * *neg);
                ++neg;
            }
        }
        while (pos != nums.end())
        {
            ret.push_back(*pos * *pos);
            ++pos;
        }
        while (neg != nums.rend())
        {
            ret.push_back(*neg * *neg);
            ++neg;
        }
        return ret;
    }
};
