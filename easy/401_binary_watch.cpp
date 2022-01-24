class Solution {
public:
    vector<vector<int>> possibleHours, possibleMins;
    constexpr static int MAX_HR_BITS{3};
    constexpr static int MAX_MIN_BITS{5};

    Solution()
        : possibleHours(MAX_HR_BITS+1, vector<int>())
        , possibleMins(MAX_MIN_BITS+1, vector<int>())
    {
        fillDicts();
    }

    void fillDicts()
    {
        auto countBits = [](int val) {
            int nbBits{};
            while (val)
            {
                nbBits += (val % 2);
                val /= 2;
            }
            return nbBits;
        };
        for (int i=0; i<12; ++i)
        {
            possibleHours[countBits(i)].push_back(i);
        }
        for (int i=0; i<60; ++i)
        {
            possibleMins[countBits(i)].push_back(i);
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ret;
        for (int nbHourBits=0; nbHourBits<=min(turnedOn, MAX_HR_BITS); ++nbHourBits)
        {
            int nbMinBits = turnedOn - nbHourBits;
            if (nbMinBits > MAX_MIN_BITS)
            {
                continue;
            }
            for (int hr : possibleHours[nbHourBits])
            {
                for (int min : possibleMins[nbMinBits])
                {
                    ostringstream o;
                    o.fill('0');
                    o << hr << ":" << setw(2) << min;
                    ret.push_back(o.str());
                }
            }
        }
        return ret;
    }
};
