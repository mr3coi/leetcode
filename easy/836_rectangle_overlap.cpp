class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool isRectangleOverlap(vector<int> const& rec1, vector<int> const& rec2) {
        return !(rec1[0] >= rec2[2] || rec1[2] <= rec2[0]
                || rec1[1] >= rec2[3] || rec1[3] <= rec2[1]);
    }
};
