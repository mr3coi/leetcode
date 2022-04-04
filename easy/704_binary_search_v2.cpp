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
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums.at(mid) == target)
            {
                return mid;
            }
            else if (nums.at(mid) > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return -1;
    }
};
