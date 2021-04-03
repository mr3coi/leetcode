class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 3) return n == 1;
        // Should have only a single 1 in binary representation
        // (if true, either 4^n or 2*4^n form)
        if ((n & (n-1)) == 0)
        {
            // 4^n - 1 = (4-1) * (...)
            return (n-1) % 3 == 0;
        }
        return false;
    }
};
