class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool lemonadeChange(vector<int>& bills) {
        std::vector<int> myBills(3, 0); //< 5 For convenience
        for (auto bill : bills)
        {
            ++myBills[bill / 10];
            if (bill == 10 && --myBills[0] < 0)
            {
                return false;
            }
            if (bill == 20)
            {
                if (myBills[0] == 0 || myBills[0] == 0 && myBills[0] < 3)
                {
                    return false;
                }
                if (myBills[1])
                {
                    --myBills[1];
                    --myBills[0];
                }
                else
                {
                    myBills[0] -= 3;
                }
            }
        }
        return true;
    }
};
