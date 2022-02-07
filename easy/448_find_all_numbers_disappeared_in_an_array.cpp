class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int range = nums.size();
        vector<bool> seen(range, false);
        for (int num : nums)
        {
            seen[num-1] = true;
        }
        vector<int> ret{};
        ret.reserve(range);
        for (int i=0; i < range; ++i)
        {
            if (!seen[i])
            {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
