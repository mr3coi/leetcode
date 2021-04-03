class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int out = (nums.size() * (nums.size()+1)) / 2;
        for (int num : nums) out -= num;
        return out;
    }
};
