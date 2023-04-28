class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool uniqueOccurrences(vector<int>& arr)
    {
        std::map<int, int> counts{};
        for (auto const num : arr)
        {
            ++counts[num];
        }
        std::unordered_set<int> uniqCounts{};
        for (auto it = counts.begin(); it != counts.end(); ++it)
        {
            if (!uniqCounts.insert(it->second).second)
            {
                return false;
            }
        }
        return true;
    }
};
