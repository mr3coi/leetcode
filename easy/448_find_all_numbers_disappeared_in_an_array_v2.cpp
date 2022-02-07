class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int range = nums.size();
        for (int num : nums)
        {
            int idx = abs(num)-1;
            if (nums[idx] > 0)
            {
                nums[idx] *= -1;
            }
        }
        vector<int> ret{};
        ret.reserve(range);
        for (int i=0; i < range; ++i)
        {
            if (nums[i] > 0)
            {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
