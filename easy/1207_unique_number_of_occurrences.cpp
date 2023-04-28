#define RANGE 2001

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
        std::vector<int> counts(RANGE, 0);
        for (auto const num : arr)
        {
            ++counts[num + 1000];
        }
        std::sort(counts.begin(), counts.end());
        for (auto it = counts.rbegin(); it != counts.rend(); ++it)
        {
            if (!*it)
            {
                break;
            }
            if (*it == *(it + 1))
            {
                return false;
            }
        }
        return true;
    }
};
