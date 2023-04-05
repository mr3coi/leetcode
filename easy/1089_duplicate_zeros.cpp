class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    void duplicateZeros(vector<int>& arr)
    {
        int nbZeroes{};
        for (auto const num : arr)
        {
            nbZeroes += (num == 0);
        }
        int const signedSize{static_cast<int>(arr.size())};
        int lastSurvivor{signedSize - 1};
        int total{signedSize + nbZeroes};
        while (total > signedSize)
        {
            total -= 1 + (arr[lastSurvivor] == 0);
            --lastSurvivor;
        }
        if (total < signedSize)
        {
            arr[signedSize - 1] = 0;
        }
        int dst = total - 1;
        while (lastSurvivor >= 0)
        {
            arr[dst--] = arr[lastSurvivor];
            if (!arr[lastSurvivor])
            {
                arr[dst--] = 0;
            }
            --lastSurvivor;
        }
    }
};
