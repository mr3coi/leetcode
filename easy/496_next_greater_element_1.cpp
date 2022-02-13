class Solution {
public:
    // Time Complexity: O(nums1.size() + nums2.size()^2)
    // Space Complexity: O(nums1.size() + nums2.size()) including return value
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record{};
        record.reserve(nums2.size());
        queue<int> notYetMatched{};

        for (int num : nums2)
        {
            size_t nbCandidates = notYetMatched.size();
            for (size_t dummy = 0; dummy < nbCandidates; ++dummy)
            {
                int const cand = notYetMatched.front();
                notYetMatched.pop();
                if (num > cand)
                {
                    record[cand] = num;
                }
                else
                {
                    notYetMatched.push(cand);
                }
            }
            notYetMatched.push(num);
        }
        while (!notYetMatched.empty())
        {
            int const cand = notYetMatched.front();
            notYetMatched.pop();
            record[cand] = -1;
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
