class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    string reverseStr(string s, int k) {
        std::vector<char> ret{s.begin(), s.end()};
        int const nbIters = (s.size() + k) / (2 * k);
        int base = 0;
        for (; base < nbIters * 2 * k; base += 2 * k)
        {
            std::reverse(ret.begin() + base, ret.begin() + base + k);
        }
        if (s.size() > base)
        {
            std::reverse(ret.begin() + base, ret.end());
        }
        return std::string(ret.begin(), ret.end());
    }
};
