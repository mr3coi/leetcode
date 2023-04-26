class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(N log N) where N = arr.size()
    // Space complexity: Theta(1) excluding return value
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int minDiff{std::numeric_limits<int>::max()};
        int pairCnt{};
        for (int i = 1; i < arr.size(); ++i)
        {
            auto const diff = arr[i] - arr[i-1];
            if (diff < minDiff)
            {
                pairCnt = 1;
                minDiff = diff;
            }
            else if (diff == minDiff)
            {
                ++pairCnt;
            }
        }
        std::vector<std::vector<int>> ret{};
        ret.reserve(pairCnt);
        for (auto it = arr.begin(); it + 1 != arr.end(); ++it)
        {
            auto const diff = static_cast<int>(*(it+1)) - *it;
            if (diff == minDiff)
            {
                ret.emplace_back(it, it + 2);
            }
        }
        return ret;
    }
};
