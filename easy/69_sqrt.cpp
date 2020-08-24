#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
	int sqrt(int x) {
		if (x == 0 or x == 1) return x;
		return sqrtHelper(x,0,x);
	}

	int sqrtHelper(int x, int lo, int hi) {
		if (lo >= hi-1) return lo;

		int mid = (lo + hi) / 2;
		unsigned long mid2 = (unsigned long) mid * (unsigned long) mid;
		if (mid2 == x) return mid;
		else if (mid2 > x) return sqrtHelper(x,lo,mid);
		else return sqrtHelper(x,mid,hi);
	}
};

int main() {
	Solution sol;
	cout << numeric_limits<int>::max() << endl;
	cout << sol.sqrt(2) << endl;
	return 0;
}
