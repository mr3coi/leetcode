class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count{};
        int bestCount{};
        for (int num : nums)
        {
            if (num)
            {
                ++count;
            }
            else
            {
                bestCount = max(count, bestCount);
                count = 0;
            }
        }
        return max(count, bestCount);
    }
};
