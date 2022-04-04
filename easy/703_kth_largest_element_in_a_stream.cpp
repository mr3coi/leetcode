class KthLargest {
    vector<int> topK; //< Sorted in descending order

public:
    KthLargest(int k, vector<int>& nums)
        : topK(k)
    {
        std::sort(nums.begin(), nums.end());
        std::copy(nums.rbegin(), nums.rend(), topK.begin());
    }
    
    int add(int val) {
        int pos = topK.size() - 1;
        for (; pos >= 0; --pos)
        {
            if (val <= topK.at(pos))
            {
                break;
            }
        }
        ++pos;
        if (pos < topK.size())
        {
            if (pos < topK.size() - 1)
            {
                for (int i = topK.size() - 2; i >= pos; --i)
                {
                    topK.at(i + 1) = topK.at(i);
                }
            }
            topK.at(pos) = val;
        }
        return topK.back();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
