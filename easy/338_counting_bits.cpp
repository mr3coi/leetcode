class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0)
        {
            return {0};
        }
        vector<int> ret{};
        ret.reserve(n + 1);
        for (int i=0; i<=1; ++i)
        {
            ret.push_back(i);
        }
        int currPower = 1;
        for (int i=2; i<=n; ++i)
        {
            if (i == currPower * 2)
            {
                currPower = i;
            }
            ret.push_back(ret.at(i-currPower) + 1);
        }
        return ret;
    }
};
