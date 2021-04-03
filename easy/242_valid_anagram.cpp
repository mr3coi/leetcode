class Solution {
public:
	bool isAnagram(const string& s, const string& t) {
		if (s.length() != t.length()) return false;
		std::vector<int> charsUsed(1<<7, 0);
		for (char c : s) ++charsUsed[c];
		for (char c : t) --charsUsed[c];
		for (int count : charsUsed) {
			if (count) return false;
		}
		return true;
	}
};
