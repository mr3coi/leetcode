class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool isOneBitCharacter(vector<int>& bits) {
        return helper(bits, 0);
    }

    bool helper(std::vector<int> const& bits, int idx)
    {
        if (bits.size() - idx <= 2)
        {
            return bits.size() - idx == 1 || bits[bits.size()-2] == 0;
        }
        return helper(bits, idx + 1 + (bits[idx] == 1));
    }
};
