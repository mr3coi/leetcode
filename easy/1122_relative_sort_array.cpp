#define MAX_ARR2_SIZE 1000

class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(N log N) where N = arr1.size()
    // Space complexity: Theta(1)
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        int const N2 = static_cast<int>(arr2.size());
        std::array<int, MAX_ARR2_SIZE + 1> tmpMap = {0}; //< Fill w/ 0's
        for (int i = 0; i < arr2.size(); ++i)
        {
            tmpMap[arr2[i]] = i - N2;
        }
        for (int& num : arr1)
        {
            if (tmpMap[num] < 0)
            {
                num = tmpMap[num];
            }
        }
        std::sort(arr1.begin(), arr1.end());
        for (int& num : arr1)
        {
            if (num < 0)
            {
                num = arr2[num + N2];
            }
        }
        return arr1;
    }
};
