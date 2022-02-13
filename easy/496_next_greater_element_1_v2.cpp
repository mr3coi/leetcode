class Solution {
public:
    // Time Complexity: O(nums1.size() + nums2.size()^2)
    // Space Complexity: O(nums1.size() + nums2.size()) including return value
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record{};
        record.reserve(nums2.size());
        stack<int> ngeCandidates{};

        for (auto it = nums2.rbegin(); it != nums2.rend(); ++it)
        {
            while (!ngeCandidates.empty() && *it >= ngeCandidates.top())
            {
                ngeCandidates.pop();
            }
            record[*it] = ngeCandidates.empty() ? -1 : ngeCandidates.top();
            ngeCandidates.push(*it);
        }

        vector<int> ret{};
        ret.reserve(nums1.size());
        for (int num : nums1)
        {
            ret.push_back(record[num]);
        }
        return ret;
    }
};
