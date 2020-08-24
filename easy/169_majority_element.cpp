class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int major = std::numeric_limits<int>::min();
		int count = 0;
		for (int num : nums) {
			if (!count) {
				++count;
				major = num;
			}
			else if (num == major) {
				++count;
			}
			else --count;
		}
		return major;
	}
};
