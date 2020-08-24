class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		std::vector<int>::iterator midIt = std::lower_bound(numbers.begin(), numbers.end(), (target+1)/2);
		int upper = midIt - numbers.begin(), lower = upper-1;
		if (target % 2 == 0 and *(midIt+1) == *midIt) {
			return std::vector<int>{upper+1,upper+2};
		}
		while (upper < numbers.size()) {
			while (numbers[upper] + numbers[lower] > target) --lower;
			if (numbers[upper] + numbers[lower] == target) {
				return std::vector<int>{lower+1,upper+1};
			}
			else ++upper;
		}
		// Dummy
		return std::vector<int>{0,0};
	}
};
