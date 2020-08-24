class Solution {
public:
	inline bool isNumeric(char c) { return ('0' <= c <= '9'); }

	inline bool isAlphabet(char c) { return ('a' <= c and c <= 'z') or ('A' <= c and c <= 'Z'); } 

	inline bool isAlphanumeric(char c) { return isAlphabet(c) or isNumeric(c); }

	bool sameChar(char c1, char c2) {
		const static char caseDiff = 'A' - 'a';
		if ('a' <= c1 and c1 <= 'z') c1 += caseDiff;
		if ('a' <= c2 and c2 <= 'z') c2 += caseDiff;
		return (c1 == c2);
	}

	bool isPalindrome(string s) {
		int front = 0, back = s.length()-1;
		while (front < s.length() and !isAlphanumeric(s.at(front))) { ++front; }
		while (back >= 0 and !isAlphanumeric(s.at(back))) { --back; }
		while (front < back) {
			if (sameChar(s.at(front), s.at(back))) {
				++front; --back;
			}
			else return false;
			while (front < s.length() and !isAlphanumeric(s.at(front))) { ++front; }
			while (back >= 0 and !isAlphanumeric(s.at(back))) { --back; }
		}
		return true;
	}
};
