/* Implement Erathosthenes' sieve, sacrificing memory for faster execution.
 * (enhanced version of v3)
 * Fewer conditional statements are used => faster
 * - Time:   O(n*log n)
 * - Memory: O(n)
 */
class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2) return 0;
		std::vector<char> isPrimes(n,1);

		// Handle 2 separately for efficiency (other primes are all odd)
		int count = 1;
		for (int idx=4; idx<n; idx+=2) isPrimes[idx] = 0;

		int div=3;
		for (; div*div<n; div+=2) {
			if (!isPrimes[div]) continue;

			// Can start from div^2 (numbers div*2, ..., div*(div-1) have
			// already been handled by preceding primes)
			for (int idx=div*div; idx<n; idx+=div) isPrimes[idx] = 0;
			++count;
		}
		for (; div<n; div+=2) count += isPrimes[div];
		return count;
	}
};
