class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        auto const toUpper = [](char c) {
            return (c >= 'a' ? c - 'a' + 'A' : c);
        };
        ostringstream o;
        int alphaCount{};
        for (char c : s)
        {
            alphaCount += (c != '-');
        }
        int firstBlockSize{alphaCount % k};
        int counter{firstBlockSize ? k : 0};
        alphaCount -= firstBlockSize;
        auto it = s.begin();
        while (it != s.end())
        {
            if (*it != '-')
            {
                if (!firstBlockSize)
                {
                    break;
                }
                o << toUpper(*it);
                --firstBlockSize;
            }
            ++it;
        }
        if (alphaCount)
        {
            while (it != s.end())
            {
                if (*it != '-')
                {
                    if (counter == k)
                    {
                        o << '-';
                        counter = 0;
                    }
                    o << toUpper(*it);
                    ++counter;
                }
                ++it;
            }
        }
        return o.str();
    }
};
