class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<char> out{};
        out.reserve(max(num1.length(), num2.length()) + 1);
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        bool carry{false};
        auto charToDigit = [](char c) -> char {
            return c - '0';
        };
        while (it1 != num1.rend() && it2 != num2.rend())
        {
            char digit = charToDigit(*it1) + charToDigit(*it2) + carry;
            carry = digit >= 10;
            digit -= carry * 10;
            out.push_back('0' + digit);
            ++it1;
            ++it2;
        }
        while (it1 != num1.rend())
        {
            char digit = charToDigit(*it1) + carry;
            carry = digit >= 10;
            digit -= carry * 10;
            out.push_back('0' + digit);
            ++it1;
        }
        while (it2 != num2.rend())
        {
            char digit = charToDigit(*it2) + carry;
            carry = digit >= 10;
            digit -= carry * 10;
            out.push_back('0' + digit);
            ++it2;
        }
        if (carry)
        {
            out.push_back('1');
        }
        return string(out.rbegin(), out.rend());
    }
};
