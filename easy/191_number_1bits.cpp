class Solution {
public:
	uint32_t hammingWeight(uint32_t n) {
		uint32_t out = 0;
		while (n) {
			out += (n % 2);
			n /= 2;
		}
		return out;
	}
};
