class Solution {
public:
    bool isPowerOfThree(int n) {
        long long num = 1;
        while (num < n)
        {
            num *= 3;
        }
        return num == n;
    }
};
