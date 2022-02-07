class Solution {
public:
    int arrangeCoins(int n) {
        if (n >= 65535 * 32768) return 65535;
        long long nn = static_cast<long long>(n) * 2;

        long long s = 1, e = 65535;
        while (s + 1 < e)
        {
            long long mid = (s + e) / 2;
            long long ref = mid * (mid + 1);
            if (ref > nn)
            {
                e = mid;
            }
            else if (ref < nn)
            {
                s = mid;
            }
            else
            {
                return mid;
            }
        }
        return s;
    }
};
