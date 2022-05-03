class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        int lo{0};
        int hi{static_cast<int>(arr.size())-1};
        while (lo + 1 < hi)
        {
            int mid = lo + (hi - lo) / 2;
            int slope = arr[mid] - arr[mid-1];
            if (slope > 0)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        return arr[lo] > arr[hi] ? lo : hi;
    }
};
