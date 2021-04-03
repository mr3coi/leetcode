class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        if (n % 2 == 0 or n % 5 == 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};
