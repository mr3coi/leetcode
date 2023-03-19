class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(arr.size())
    // Space complexity: Theta(1)
    bool canThreePartsEqualSum(vector<int>& arr)
    {
        int sum = std::accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3)
        {
            return false;
        }
        sum /= 3;
        int partitionSum{};
        auto startPttn = arr.begin();
        for (; startPttn != arr.end(); ++startPttn)
        {
            partitionSum += *startPttn;
            if (partitionSum == sum)
            {
                break;
            }
        }
        if (startPttn == arr.end())
        {
            // No valid first pttn => fail.
            return false;
        }
        ++startPttn; //< Move to start of the second pttn.
        partitionSum = 0;
        auto endPttn = arr.rbegin();
        for (; endPttn != arr.rend(); ++endPttn)
        {
            partitionSum += *endPttn;
            if (partitionSum == sum)
            {
                break;
            }
        }
        if (endPttn == arr.rend())
        {
            // No valid third pttn => fail.
            return false;
        }
        int endPttnSize = endPttn - arr.rbegin() + 1;
        int startPttnSize = startPttn - arr.begin();
        int midPttnSize = arr.size() - endPttnSize - startPttnSize;
        return midPttnSize <= 0
            ? false
            : std::accumulate(startPttn, startPttn + midPttnSize, 0) == sum;
    }
};
