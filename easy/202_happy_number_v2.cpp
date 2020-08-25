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
		int slow = n, fast = n;
		while (1) {
			slow = sumSqDigits(slow);
			fast = sumSqDigits(fast); fast = sumSqDigits(fast);
			if (fast == slow) break;
		}
		return (slow == 1);
	}
};
