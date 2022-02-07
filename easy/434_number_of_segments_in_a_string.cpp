class Solution {
public:
    int countSegments(string s) {
        int ret{};
        bool inSegment{false};
        for (char c : s)
        {
            if (c == ' ')
            {
                inSegment = false;
            }
            else if (!inSegment)
            {
                ++ret;
                inSegment = true;
            }
        }
        return ret;
    }
};
