class Solution {
public:
	int findGCD(int a, int b) {
		while (a > 1 and b > 1) {
			int small = std::min(a, b), large = std::max(a, b);
			if (large % small == 0) return small;
			else {
				a = large % small;
				b = small;
			}
		}
		return 1;
	}

	void rotateHelper(vector<int>& nums, int k, int start, int rep) {
		int buf = nums[start], movesLeft = rep-1, dest = start;
		while (movesLeft) {
			int src = (dest + nums.size() - k) % nums.size();
			nums[dest] = nums[src];
			dest = src;
			--movesLeft;
		}
		nums[dest] = buf;
	}

	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k %= n;
		if (!k) return;
		int gcd = findGCD(n, k);
		for (int start=0; start<gcd; ++start) rotateHelper(nums, k, start, n/gcd);
	}
};
