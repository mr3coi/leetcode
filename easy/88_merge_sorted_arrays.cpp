#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;

		if (m > 0) {
			int m_curr = nums1[m-1], n_curr = nums2[n-1];
			for (int end_ptr=nums1.size()-1;m>0 && n>0;--end_ptr) {
				if (m_curr >= n_curr) {
					nums1[end_ptr] = m_curr;
					--m;
					if (m > 0) m_curr = nums1[m-1];
				} else {
					nums1[end_ptr] = n_curr;
					--n;
					if (n > 0) n_curr = nums2[n-1];
				}
			}
		}
		// Ignored if n == 0
		for (int i=0; i<n; ++i) {
			nums1[i] = nums2[i];
		}
	}
};

int main() {
	vector<int> nums1 = {1,2,3}, nums2 = {2,5,6};
	int m = nums1.size();
	for (int i : nums2) {
		nums1.push_back(0);
	}
	Solution sol;
	sol.merge(nums1, m, nums2, nums2.size());
	for (int item : nums1) {
		cout << item << ' ';
	}
	cout << endl;
	return 0;
}
