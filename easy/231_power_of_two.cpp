class Solution {
public:
	bool isPowerOfTwo(int n) {
		long cmp = 1;
		while (cmp < n) cmp *= 2;
		return (cmp == n);
	}
};
