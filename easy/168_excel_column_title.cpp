class Solution {
public:
	string convertToTitle(int n) {
		const static int nbDigits = 'Z' - 'A' + 1;
		int power = 1;
		long chunk = nbDigits, number = n;
		while (number > chunk) {
			number -= chunk;
			++power;
			chunk *= nbDigits;
		}
		--number;
		chunk /= nbDigits;
		string output = "";
		for (int i=0; i<power-1; ++i) {
			output += (char)('A' + number / chunk);
			number %= chunk;
			chunk /= nbDigits;
		}
		output += (char)('A' + number);
		return output;
	}
};
