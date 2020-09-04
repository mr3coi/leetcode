class Solution {
public:
	/* No need to record which letter in s maps to which in t.
	 * Just keep record of at which position a letter in s and a letter in t
	 * have been "occupied". At each position, the pair of letters
	 * must either be unoccupied simultaneously, or be occupied
	 * at the same position.
	 */
	bool isIsomorphic(string s, string t) {
		std::vector<char> smap(1<<7, -1), tmap(1<<7, -1);
		for (int i=0; i<s.length(); ++i) {
			if (smap[s[i]] == tmap[t[i]]) {
				smap[s[i]] = i;
				tmap[t[i]] = i;
			}
			else return false;
		}
		return true;
	}
};
