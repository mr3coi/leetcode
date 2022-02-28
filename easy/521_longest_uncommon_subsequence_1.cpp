class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int findLUSlength(string a, string b) {
        return (a.compare(b) == 0 ? -1 : std::max(a.size(), b.size()));
    }
};
