class Solution {
public:
	int titleToNumber(string s) {
		const static long NB_DIGITS = 'Z' - 'A' + 1;
		long output = 0, power = 1;

		// Consider individual characters
		for (int pos=s.length()-1; pos>=0; --pos) {
			output += (s.at(pos) - 'A' + 1) * power;
			power *= NB_DIGITS;
		}

		return output;
	}
};
