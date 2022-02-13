class Solution {
public:
    int findComplement(int num) {
        int filled{1};
        while (filled < num)
        {
            filled <<= 1;
            filled += 1;
        }
        return num ^ filled;
    }
};
