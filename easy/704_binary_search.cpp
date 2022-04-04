class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int search(vector<int>& nums, int target) {
        int lo{0};
        int hi{static_cast<int>(nums.size()) - 1};
        while (lo + 1 < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums.at(mid) == target)
            {
                return mid;
            }
            else if (nums.at(mid) > target)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        if (nums.at(lo) == target)
        {
            return lo;
        }
        else if (nums.at(hi) == target)
        {
            return hi;
        }
        return -1;
    }
};
