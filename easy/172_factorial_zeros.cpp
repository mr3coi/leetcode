class Solution {
public:
	int trailingZeroes(int n) {
		long power = 5, output = 0;
		while (power <= n) {
			output += (n / power);
			power *= 5;
		}
		return output;
	}
};
