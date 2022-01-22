class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0, end = num;
        while (start + 1 < end)
        {
            long long mid = start + (end - start) / 2;
            long long midsq = mid * mid;
            if (midsq < num)
            {
                start = mid;
            }
            else if (midsq > num)
            {
                end = mid;
            }
            else
            {
                return true;
            }
        }
        auto startSq = static_cast<long long>(start) * start;
        auto endSq = static_cast<long long>(end) * end;
        return num == startSq || num == endSq;
    }
};
