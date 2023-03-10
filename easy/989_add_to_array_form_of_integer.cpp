class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(num.size() + log k)
    // Space complexity: Theta(1)
    vector<int> addToArrayForm(vector<int>& num, int k)
    {
        std::vector<int> ret;
        // Output will be at least as long as num.
        ret.reserve(num.size());
        auto arrDigit = num.rbegin();
        int carry{};

        while (k)
        {
            int digit = (arrDigit != num.rend() ? *arrDigit++ : 0)
                        + k % 10 + carry;
            carry = static_cast<int>(digit >= 10);
            digit -= carry * 10:
            ret.push_back(digit);
            k /= 10;
        }
        while (arrDigit != num.rend())
        {
            int digit = *arrDigit++ + carry;
            carry = static_cast<int>(digit >= 10);
            digit -= carry * 10;
            ret.push_back(digit);
        }
        if (carry)
        {
            ret.push_back(carry);
        }
        std::reverse(ret.rbegin(), ret.rend());
        return ret;
    }
};
