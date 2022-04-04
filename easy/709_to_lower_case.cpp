class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    string toLowerCase(string s) {
        std::ostringstream o;
        for (char c : s)
        {
            o << (c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c);
        }
        return o.str();
    }
};
