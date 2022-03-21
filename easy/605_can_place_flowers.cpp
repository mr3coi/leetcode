class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool leftIsEmpty{true};
        for (int i = 0; i < flowerbed.size(); ++i)
        {
            if (!flowerbed[i])
            {
                if (leftIsEmpty && (i + 1 == flowerbed.size() || !flowerbed[i+1]))
                {
                    --n;
                    ++i;
                }
                leftIsEmpty = true;
            }
            else
            {
                leftIsEmpty = false;
            }
        }
        return n <= 0;
    }
};
