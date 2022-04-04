class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    int k;

public:
    KthLargest(int k_, vector<int>& nums)
        : heap(nums.begin(), nums.end()), k{k_}
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);

        // Keep the largest k elements in heap, in ascending order.
        for (int i = 0; i < std::max(0, static_cast<int>(nums.size()) - k); ++i)
        {
            heap.pop();
        }
    }
    
    int add(int val) {
        if (heap.size() < k || val > heap.top())
        {
            heap.push(val);
        }
        if (heap.size() > k)
        {
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
