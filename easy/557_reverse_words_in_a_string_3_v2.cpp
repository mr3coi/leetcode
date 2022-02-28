class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    string reverseWords(string s) {
        ostringstream o;
        int pos = 0;
        // Bypass leading spaces (as redundant measure)
        while (s.at(pos) == ' ')
        {
            ++pos;
        }
        int currWordStart{pos};

        // start: inclusive, end: exclusive
        auto insertReverseToStream = [&](int start, int end) {
            int rStart = s.size() - end; // rStart: Start-inclusive
            int rEnd = s.size() - start; // rEnd: End-exclusive
            for (auto it = s.rbegin() + rStart; it != s.rbegin() + rEnd; ++it)
            {
                o << *it;
            }
        };
        for (; pos < s.size(); ++pos)
        {
            if (s.at(pos) == ' ')
            {
                insertReverseToStream(currWordStart, pos);
                o << ' ';
                // Bypass spaces between words (as redundant measure)
                while (pos < s.size() && s.at(pos) == ' ')
                {
                    ++pos;
                }
                currWordStart = pos;
            }

        }
        if (currWordStart < pos)
        {
            insertReverseToStream(currWordStart, s.size());
        }
        return o.str();
    }
};
