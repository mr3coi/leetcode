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

    int search(vector<int> const& nums, int target)
    {
        int lo{0};
        int hi{static_cast<int>(nums.size()) - 1};
        int mid{};
        // Search for the "discontinuity", if rotated.
        if (nums.at(lo) > nums.at(hi))
        {
            int lo2{lo};
            int hi2{hi};
            auto const f1 = [&](int x) {
                return nums.at(x) < nums.at(lo);
            };
            hi2 = binSearch(lo2, hi2, f1);
            // Determine the subdomain to search in.
            if (target >= nums.at(lo))
            {
                hi = hi2 - 1;
            }
            else
            {
                lo = hi2;
            }
        }
        // Search within the relevant subdomain.
        auto const f2 = [&](int x) {
            return nums.at(x) >= target;
        };
        hi = binSearch(lo, hi, f2);
        return hi >= 0 && nums.at(hi) == target ? hi : -1;
    }
};
