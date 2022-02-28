class Solution {
    static int const BASE{7};
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    string convertToBase7(int num) {
        if (!num)
        {
            return "0";
        }
        ostringstream o;
        if (num < 0)
        {
            o << '-';
            num *= -1;
        }
        int power = 1;
        while (power * BASE <= num)
        {
            power *= BASE;
        }
        while (power)
        {
            int digit{};
            while (power <= num)
            {
                ++digit;
                num -= power;
            }
            o << digit;
            power /= BASE;
        }
        return o.str();
    }
};
