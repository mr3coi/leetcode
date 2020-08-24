class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int upper = numbers.size()-1, lower = 0;
		while (upper > lower) {
			while (numbers[upper] + numbers[lower] < target) ++lower;
			if (numbers[upper] + numbers[lower] == target) {
				return std::vector<int>{lower+1,upper+1};
			}
			else --upper;
		}
		// Dummy
		return std::vector<int>{0,0};
	}
};
