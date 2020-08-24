#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		string token;
		stringstream sstream(s);
		int output = 0;

		while (getline(sstream, token, ' ')) {
			if (token.size() > 0) { output = token.size(); }
		}
		return output;
	}
};

int main() {
	Solution sol;
	string input = "  Hello  World    ";
	cout << sol.lengthOfLastWord(input) << endl;
}
