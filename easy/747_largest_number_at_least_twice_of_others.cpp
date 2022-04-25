class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int dominantIndex(vector<int>& nums) {
        int largest{-1};
        int largestIdx{};
        int secondLargest{-1};
        int secondLargestIdx{};
        for (int i = 0; i < nums.size(); ++i)
        {
            auto const num = nums.at(i);
            if (num > secondLargest)
            {
                if (num > largest)
                {
                    secondLargest = largest;
                    secondLargestIdx = largestIdx;
                    largest = num;
                    largestIdx = i;
                }
                else
                {
                    secondLargest = num;
                    secondLargestIdx = i;
                }
            }
        }
        return largest >= 2 * secondLargest ? largestIdx : -1;
    }
};
