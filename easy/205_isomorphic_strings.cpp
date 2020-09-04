class Solution {
public:
	/* Keeps record of which letter in s maps to which in t,
	 * and vice versa. The two maps must agree at each position
	 * in the two strings.
	 */
	bool isIsomorphic(string s, string t) {
		std::vector<char> smap(1<<7, -1), tmap(1<<7, -1);
		auto s1 = s.cbegin();
		auto t1 = t.cbegin();
		for (; s1 != s.cend(); ++s1, ++t1) {
			if (smap[*s1] == -1) {
				if (tmap[*t1] != -1) return false;
				smap[*s1] = *t1;
				tmap[*t1] = *s1;
			}
			else if (smap[*s1] != *t1) return false;
		}
		return true;
	}
};
