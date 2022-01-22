class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        constexpr size_t MAX_VAL{1000};
        std::vector<int> count1(MAX_VAL+1, 0);
        std::vector<int> count2(MAX_VAL+1, 0);
        for (int num : nums1)
        {
            ++count1[num];
        }
        for (int num : nums2)
        {
            ++count2[num];
        }
        std::vector<int> ret{};
        for (int i=0; i<=MAX_VAL; ++i)
        {
            for (int j=0; j < std::min(count1[i], count2[i]); ++j)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
