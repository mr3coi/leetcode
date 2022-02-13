class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist{};
        long long power{1LL << 32};
        long long xl{x}, yl{y};
        while (power)
        {
            if (power > xl)
            {
                if (power <= yl)
                {
                    yl -= power;
                    ++dist;
                }
                else
                {
                    ;
                }
            }
            else // power <= xl
            {
                if (power <= yl)
                {
                    xl -= power;
                    yl -= power;
                }
                else
                {
                    xl -= power;
                    ++dist;
                }
            }
            power >>= 1U;
        }
        return dist;
    }
};
