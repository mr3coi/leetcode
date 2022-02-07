class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int>> uniqNums(nums.begin(), nums.end());
        auto retPtr = uniqNums.begin();
        if (uniqNums.size() >= 3)
        {
            ++retPtr; ++retPtr;
        }
        return *retPtr;
    }
};
