class Solution {
public:
    int addDigits(int num) {
        if (num % 10 == 0) return num;
        int out = 0;
        while (num)
        {
            out += num % 10;
            num /= 10;
        }
        return addDigits(out);
    }
};
