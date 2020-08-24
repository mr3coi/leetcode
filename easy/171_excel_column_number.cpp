class Solution {
public:
	int titleToNumber(string s) {
		const static int NB_DIGITS = 'Z' - 'A' + 1;
		int len = s.length(), output = 1, power = 1;

		// First compute number for AA...A (same length as s)
		for (int digit=1; digit<len; ++digit) {
			power *= NB_DIGITS;
			output += power;
		}

		// Consider individual characters
		for (int pos=0; pos<len; ++pos) {
			output += (s.at(pos) - 'A') * power;
			power /= NB_DIGITS;
		}

		return output;
	}
};
