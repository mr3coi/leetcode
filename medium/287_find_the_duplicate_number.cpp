class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Execute binary search on a 0-1 "single-step" function f.
    // Find the lower bound of the domain where f == 1.
    int binSearch(int lo, int hi, std::function<bool(int)> const& f)
    {
        if (f(lo))
        {
            return lo;
        }
        if (!f(hi))
        {
            return -1;
        }
        while (lo + 1 < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (f(mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        return hi;
    }

    // Do binary search on range [1, n] to locate the repeated number.
    int findDuplicate(vector<int> const& nums) {
        int const n{static_cast<int>(nums.size())-1};
        auto const f = [&nums](int mid) {
            return mid < std::count_if(nums.begin(), nums.end(),
                    [mid](int num) { return num <= mid; });
        };
        return binSearch(1, n, f);
    }
};
