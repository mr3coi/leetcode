class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t out = 0, power = 1<<31;
		while (n) {
			out += (n % 2) * power;
			n /= 2;
			power /= 2;
		}
		return out;
	}
};
