class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(N*log N) where N = stones.size()
    // Space complexity: Theta(1)
    int lastStoneWeight(vector<int>& stones)
    {
        int size = stones.size();

        // Build a max-heap.
        while (size > 1)
        {
            std::make_heap(stones.begin(), stones.begin() + size);
            std::swap(stones[0], stones[size-1]);
            std::make_heap(stones.begin(), stones.begin() + size - 1);
            std::swap(stones[0], stones[size-2]);
            stones[size-2] = stones[size-1] - stones[size-2];
            size -= 1 + (stones[size-2] == 0);
        }
        return size ? stones[0] : 0;
    }
};
