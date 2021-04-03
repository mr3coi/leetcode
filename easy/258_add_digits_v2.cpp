class Solution {
public:
    int addDigits(int num) {
        if (!num) return 0;
        num %= 9;
        return num ? num : 9;
    }
};
