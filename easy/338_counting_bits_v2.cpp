class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1, 0);
        for (int i=0; i<=n; ++i)
        {
            ret.at(i) = ret.at(i/2);
            if (i % 2 == 1)
            {
                ++ret.at(i);
            }
        }
        return ret;
    }
};
