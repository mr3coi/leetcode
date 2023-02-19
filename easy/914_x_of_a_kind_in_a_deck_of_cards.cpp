#define MAX_NB_CARDS 10000

class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int gcd(int a, int b)
    {
        int max = std::max(a, b);
        int min = std::min(a, b);
        while (min)
        {
            int backup = max;
            max = min;
            min = backup % min;
        }
        return max;
    }

    // Time complexity: O(deck.size()) amortized (due to unordered_map)
    // Space complexity: O(deck.size())
    bool hasGroupsSizeX(vector<int>& deck)
    {
        std::unordered_map<int, int> counts;
        for (auto const card : deck)
        {
            // Zero-initialized if the key is missing in the map.
            ++counts[card];
        }
        int smallestPtnSize{counts.begin()->second};
        for (auto const& pair : counts)
        {
            smallestPtnSize = gcd(smallestPtnSize, pair.second);
            if (smallestPtnSize == 1)
            {
                return false;
            }
        }
        return true;
    }
};
