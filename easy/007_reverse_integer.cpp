class Solution {
public:
	int reverse(int x) {
		if (x == std::numeric_limits<int>::min()) return 0;
		int sign = (x > 0) * 2 - 1;
		x *= sign;
		long output = 0;
		while (x) {
			int digit = x % 10;
			x /= 10;
			output = output * 10 + static_cast<long>(digit);
			if ((sign > 0 and output > std::numeric_limits<int>::max())
					or (sign < 0 and output > static_cast<long>(std::numeric_limits<int>::min()) * -1)) {
				return 0;
			}
		}
		return static_cast<int>(output) * sign;
	}
};
