class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nextLoc = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            if (nums.at(i) != 0)
            {
                nums.at(nextLoc++) = nums.at(i);
            }
        }
        if (!nextLoc) return;
        for (; nextLoc < nums.size(); ++nextLoc)
        {
            nums.at(nextLoc) = 0;
        }
    }
};
