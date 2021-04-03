class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroCount = 0;
        for (int num : nums)
        {
            nonZeroCount += (num != 0);
        }
        if (nonZeroCount == 0 or nonZeroCount == nums.size())
        {
            return;
        }
        int nextLoc = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            if (nums.at(i) != 0)
            {
                nums.at(nextLoc++) = nums.at(i);
                if (nextLoc == nonZeroCount) break;
            }
        }
        for (; nextLoc < nums.size(); ++nextLoc)
        {
            nums.at(nextLoc) = 0;
        }
    }
};
