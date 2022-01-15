#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.compare("0") == 0) return b;
		if (b.compare("0") == 0) return a;
		int maxlen = max(a.size(), b.size());
		vector<char> output;
		output.reserve(maxlen+1);
		string longer, shorter;

		if (a.size() > b.size()) {
			longer = a; shorter = b;
		} else {
			longer = b; shorter = a;
		}
		bool raise = false;

		for (auto it1=longer.end()-1, it2=shorter.end()-1;
				it1>=longer.begin() && it2>=shorter.begin();
				--it1, --it2) {
			int i1 = *it1 - '0', i2 = *it2 - '0';
			int val = i1 + i2 + raise;
			if (val == 2) {
				val -= 2;
				raise = true;
			} else {
				raise = false;
			}
			output.push_back(val + '0');
		}

		for (auto it1=longer.end()-output.size()-1; it1>=longer.begin(); --it1) {
			int i1 = *it1 - '0';
			int val = i1 + raise;
			if (val >= 2) {
				val -= 2;
				raise = true;
			} else {
				raise = false;
			}
			output.push_back(val + '0');
		}
		if (raise) { output.push_back('1'); }

		return string(output.rbegin(),output.rend());
	}
};

int main() {
	Solution sol;
	string input1 = "1", input2 = "1";
	string out = sol.addBinary(input1, input2);
	cout << out << endl;

	return 0;
}
