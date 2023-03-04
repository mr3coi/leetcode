class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(strs.size() * strs[0].size())
    // Space complexity: Theta(strs[0].size())
    int minDeletionSize(vector<string>& strs)
    {
        if (strs.size() == 1)
        {
            return 0;
        }
        std::vector<bool> toDelete(strs[0].size(), false);
        for (int r = 1; r < strs.size(); ++r)
        {
            auto const& curr = strs[r];
            auto const& last = strs[r-1];
            for (int c = 0; c < strs[0].size(); ++c)
            {
                if (toDelete[c])
                {
                    continue;
                }
                if (curr[c] < last[c])
                {
                    toDelete[c] = true;
                }
            }
        }
        return std::accumulate(toDelete.begin(), toDelete.end(), 0);
    }
};
