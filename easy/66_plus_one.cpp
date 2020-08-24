#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		//vector<int> output(digits);
		bool raise = true;	// Plus one
		for (int i=n-1;i>=0;--i) {
			if (raise) {
				++digits[i];
				if (digits[i] > 9) { digits[i] = 0; }
				else { raise = false; }
			}
			else break;
		}
		if (raise) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

int main() {
	vector<int> tmp = {3,5,9};
	Solution* sol = new Solution();
	vector<int> out = sol->plusOne(tmp);
	for (int i=0;i<out.size();++i) {
		cout << out[i] << " ";
	}
	cout << endl;
}
