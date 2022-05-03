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
            int oneThird = lo + (hi - lo) / 3;
            int twoThird = lo + (hi - lo) * 2 / 3;
            if (arr[oneThird] < arr[twoThird])
            {
                lo = oneThird + 1;
            }
            else if (arr[oneThird] > arr[twoThird])
            {
                hi = twoThird - 1;
            }
            else
            {
                lo = oneThird + 1;
                hi = twoThird - 1;
            }
        }
        return arr[lo] > arr[hi] ? lo : hi;
    }
};
