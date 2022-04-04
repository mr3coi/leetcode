class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int findShortestSubArray(vector<int>& nums) {
        // {num, (startIdx, count)}
        std::unordered_map<int, std::pair<int, int>> records{};
        int modeCount{0};
        int ret{INT_MAX};
        for (int i = 0; i < nums.size(); ++i)
        {
            auto const num = nums.at(i);
            // Corner case: when no number occurs twice
            if (records.find(num) == records.end())
            {
                records[num] = {i, 1};
            }
            else
            {
                auto& record = records.at(num);
                ++record.second;
                if (record.second > modeCount)
                {
                    modeCount = record.second;
                    ret = i - record.first + 1;
                }
                else if (record.second == modeCount)
                {
                    ret = std::min(ret, i - record.first + 1);
                }
            }
        }
        return ret == INT_MAX ? 1 : ret;
    }
};
