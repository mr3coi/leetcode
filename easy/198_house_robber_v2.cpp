class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		else if (nums.size() == 1) return nums.front();
		auto it = nums.rbegin()+1;
		*it = std::max(*it, *(it-1));
		for (++it; it!=nums.rend(); ++it) {
			*it = std::max(*it + *(it-2), *(it-1));
		}
		for (int num : nums) cout << num << ' ';
		return nums.front();
	}
};
