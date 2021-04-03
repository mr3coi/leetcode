// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Guarantees false at 1, true at n
        // Also covers n == 1 case
        if (isBadVersion(1)) return 1;
        return firstBadVersionHelper(1, n);
    }

    int firstBadVersionHelper(int start, int end) {
        if (start + 1 == end) return end;

        int mid = start + (end-start) / 2;
        if (isBadVersion(mid)) return firstBadVersionHelper(start, mid);
        else return firstBadVersionHelper(mid, end);
    }
};
