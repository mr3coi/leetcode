class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret{};
        if (nums.empty())
        {
            return ret;
        }
        auto flush = [&ret](int start, int end) -> void {
            ostringstream o;
            o << start;
            if (end != start)
            {
                o << "->" << end;
            }
            ret.push_back(o.str());
        };
        int start = nums.at(0), end = nums.at(0);
        for (int curr : nums)
        {
            // Use <= to cover the first element.
            if (curr <= end + 1)
            {
                end = curr;
            }
            else
            {
                flush(start, end);
                start = curr;
                end = curr;
            }
        }
        flush(start, end);
        return ret;
    }
};
