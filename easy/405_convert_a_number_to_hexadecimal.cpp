class Solution {
public:
    // Little-endian.
    char bitsToHexDigit(vector<char>::reverse_iterator it)
    {
        char val = 8 * *it + 4 * *(it+1) + 2 * *(it+2) + 1 * *(it+3);
        return val > 9 ? 'a' + val - 10 : '0' + val;
    }

    string convertBinaryToHex(vector<char> bitsInReverse)
    {
        auto it = bitsInReverse.rbegin();
        ostringstream out;
        bool started{false};
        while (it != bitsInReverse.rend())
        {
            char hex = bitsToHexDigit(it);
            if (started)
            {
                out << hex;
            }
            else if (hex != '0')
            {
                started = true;
                out << hex;
            }
            it += 4;
        }
        return out.str();
    }

    string toHex(int num) {
        if (!num)
        {
            return "0";
        }
        if (num == numeric_limits<int>::min())
        {
            return "80000000";
        }
        vector<char> outInReverse;
        bool doTwosComplement{num < 0};
        num *= (1 - 2 * doTwosComplement);
        // Get bit representation.
        while (num)
        {
            outInReverse.push_back(num % 2);
            num /= 2;
        }
        // Pad for hex representation.
        if (outInReverse.size() < 32)
        {
            size_t padNeeded = 32 - outInReverse.size();
            for (size_t i=0; i < padNeeded; ++i)
            {
                outInReverse.push_back(0);
            }
        }
        if (doTwosComplement)
        {
            // Get one's complement.
            for (size_t i=0; i<outInReverse.size(); ++i)
            {
                outInReverse[i] = 1 - outInReverse[i];
            }
            // Add 1 if negative.
            bool overflow{true};
            for (size_t i=0; i<outInReverse.size(); ++i)
            {
                outInReverse[i] += 1;
                overflow = outInReverse[i] == 2;
                if (overflow)
                {
                    outInReverse[i] = 0;
                }
                else
                {
                    // Stop if no overflow.
                    break;
                }
            }
            if (overflow)
            {
                // Insert in reverse order.
                outInReverse.push_back(1);
                outInReverse.push_back(0);
                outInReverse.push_back(0);
                outInReverse.push_back(0);
            }
        }
        return convertBinaryToHex(outInReverse);
    }
};
