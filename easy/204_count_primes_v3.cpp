/* Implement Erathosthenes' sieve, sacrificing memory for faster execution.
 * Fewer conditional statements are used => faster
 * - Time:   O(n*log n)
 * - Memory: O(n)
 *
 * NOTE: Changing `isPrimes` to `vector<bool>` reduces memory significantly,
 * but increases runtime due to implicit casting from bool to int
 */
class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2) return 0;
		std::vector<char> isPrimes(n,1);
		isPrimes[0] = isPrimes[1] = 0;

		for (int idx=4; idx<n; idx+=2) isPrimes[idx] = 0;

		for (int div=3; div*div<n; div+=2) {
			if (!isPrimes[div]) continue;
			for (int idx=div*2; idx<n; idx+=div) isPrimes[idx] = 0;
		}

		int count = 0;
		for (char flag : isPrimes) count += flag;
		return count;
	}
};
