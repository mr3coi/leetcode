class Solution {
public:
	int sumSqDigits(int n) {
		int out = 0;
		while (n) {
			int digit = (n % 10);
			out += digit * digit;
			n /= 10;
		}
		return out;
	}

	bool isHappy(int n) {
		if (n <= 0) return false;
		std::unordered_set<int> alreadyVisited;
		alreadyVisited.insert(n);
		while (1) {
			n = sumSqDigits(n);
			if (n == 1) break;
			else if (alreadyVisited.find(n) != alreadyVisited.end()) return false;
			alreadyVisited.insert(n);
		}
		return true;
	}
};
