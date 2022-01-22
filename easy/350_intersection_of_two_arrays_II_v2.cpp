class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::multiset<int> set1(nums1.begin(), nums1.end());
        std::multiset<int> set2(nums2.begin(), nums2.end());
        std::vector<int> ret{};
        for (auto it1=set1.begin(), it2=set2.begin();
             it1 != set1.end() && it2 != set2.end();)
        {
            if (*it1 < *it2)
            {
                ++it1;
            }
            else if (*it1 > *it2)
            {
                ++it2;
            }
            else
            {
                ret.push_back(*it1);
                ++it1;
                ++it2;
            }
        }
        return ret;
    }
};
