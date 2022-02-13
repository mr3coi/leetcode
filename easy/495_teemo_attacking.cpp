class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    // Time Complexity: Omega(timeSeries.size())
    // Space Complexity: Omega(1)
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // Guaranteed >= 1 attack(s), last attack always goes full duration
        int ret{duration};
        int lastAtk{timeSeries[0]};
        for (auto it = timeSeries.begin()+1; it != timeSeries.end(); ++it)
        {
            auto const& atk = *it;
            ret += (atk < lastAtk + duration) ? (atk - lastAtk) : duration;
            lastAtk = atk;
        }
        return ret;
    }
};
