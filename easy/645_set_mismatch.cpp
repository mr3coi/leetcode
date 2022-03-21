class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<int> findErrorNums(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int observedSum{std::accumulate(nums.begin(), nums.end(), 0)};
        int duplicate{};
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums.at(i) == nums.at(i-1))
            {
                duplicate = nums.at(i);
                break;
            }
        }
        int expectedSum = nums.size() * (nums.size() + 1) / 2;
        return {duplicate, expectedSum + duplicate - observedSum};
    }
};
