class Solution {
public:
    string licenseKeyFormatting(string const s, int k) {
        auto const toUpper = [](char c) {
            return (c >= 'a' ? c - 'a' + 'A' : c);
        };
        std::vector<char> buf(s.begin(), s.end());
        int count{};
        int const len{static_cast<int>(s.length())};
        for (int curr=0; curr < len; ++curr)
        {
            cout << curr << ", " << count << endl;
            if (buf[curr] != '-')
            {
                buf[count++] = toUpper(buf[curr]);
            }
        }
        if (!count)
        {
            return std::string();
        }
        int const expectedSize{count + count / k - (count % k == 0)};
        buf.resize(expectedSize);
        for (int curr=count-1, blkSize=0, loc=expectedSize-1; loc >= 0; --loc)
        {
            if (blkSize == k)
            {
                buf[loc] = '-';
                blkSize = 0;
            }
            else
            {
                buf[loc] = buf[curr--];
                ++blkSize;
            }
        }
        return std::string(buf.begin(), buf.end());
    }
};
