class Solution {
public:
    bool isPowerOfFour(int n) {
        long long num = 1;
        while (num < n) num *= 4;
        return num == n;
    }
};
