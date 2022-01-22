class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> set1(nums1.begin(), nums1.end());
        std::set<int> set2(nums2.begin(), nums2.end());
        std::vector<int> ret(1000);
        auto it = std::set_intersection(set1.begin(), set1.end(),
            set2.begin(), set2.end(), ret.begin());
        ret.resize(it - ret.begin());
        return ret;
    }
};
