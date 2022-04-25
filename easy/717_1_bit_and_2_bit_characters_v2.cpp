class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool isOneBitCharacter(vector<int>& bits) {
        int idx{0};
        while (bits.size() - idx > 2)
        {
            idx += 1 + (bits[idx] == 1);
        }
        return bits.size() - idx == 1 || bits[bits.size()-2] == 0;
    }
};
