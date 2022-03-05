class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int distributeCandies(vector<int>& candyType) {
        auto const nbTypes = std::unordered_set(candyType.begin(), candyType.end()).size();
        return std::min(nbTypes, candyType.size() / 2);
    }
};
