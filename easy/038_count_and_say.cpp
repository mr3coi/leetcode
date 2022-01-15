#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string input = "1";
		vector<int> output;
		output.reserve(100000);

		while (--n) {
			output.push_back(0);
			output.push_back(input[0] - '0');

			ostringstream vts;

#ifdef DEBUG
			cout << n << ", \"" << input << "\"" << ", length = " << input.length() << endl;
#endif

			for (int i=0;i<input.length();++i) {
				int elem = input[i] - '0';

#ifdef DEBUG
				cout << "\t>> " << i << ", " << elem << endl;
#endif

				if (output[output.size()-1] == elem) {
					++output[output.size()-2];
				}
				else {
					output.push_back(1);
					output.push_back(elem);
				}
			}

#ifdef DEBUG
			cout << ">>> Output: ";
			for (int item: output) {
				cout << item << ", ";
			}
			cout << endl;
#endif

			copy(output.begin(), output.end(),
				 ostream_iterator<int>(vts,""));

			input = vts.str();
#ifdef DEBUG
			cout << "input after update: " << input << endl;
#endif
			output.clear();
		}
		return input;
	}
};

int main() {
	int n;
	auto sol = Solution();
	cin >> n;
	assert(n > 0);
	cout << sol.countAndSay(n) << endl;

	return 0;
}
