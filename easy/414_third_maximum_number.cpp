class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first{numeric_limits<long long>::min()};
        long long second{numeric_limits<long long>::min()};
        long long third{numeric_limits<long long>::min()};
        for (int num : nums)
        {
            if (num > first)
            {
                third = second;
                second = first;
                first = num;
            }
            else if (num < first && num > second)
            {
                third = second;
                second = num;
            }
            else if (num < second && num > third)
            {
                third = num;
            }
        }
        return static_cast<int>(third == numeric_limits<long long>::min() ?
                first : third);
    }
};
