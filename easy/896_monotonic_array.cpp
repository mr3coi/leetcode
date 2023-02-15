class Solution {
public:
    bool isMonotonic(vector<int>& nums)
    {
        if (nums.size() <= 1)
        {
            return true;
        }
        bool increased{false};
        bool decreased{false};
        auto last{nums[0]};
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > last)
            {
                increased = true;
            }
            else if (nums[i] < last)
            {
                decreased = true;
            }
            if (increased && decreased)
            {
                return false;
            }
            last = nums[i];
        }
        return true;
    }
};
