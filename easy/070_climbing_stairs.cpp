#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		vector<int> cache(n+1, -1);
		return climbHelper(n, cache);
	}

	int climbHelper(int n, vector<int>& cache) {
		if (n == 0 or n == 1) return 1;
		int& val = cache[n];
		if (val >= 0) return val;
		val = climbHelper(n-1, cache) + climbHelper(n-2, cache);
		return val;
	}

	void printCache(vector<int>& cache) {
		for (int item : cache) cout << item << ' ';
		cout << endl;
	}
};

int main() {
	Solution sol;
	cout << sol.climbStairs(40) << endl;

	return 0;
}
