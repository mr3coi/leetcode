/* Keeps record of all primes found (at most sqrt(n)),
 * to speed up the process of checking whether a number is prime
 * - Time:  o(n^1.5)
 * - Space: o(n^0.5)
 */
class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2) return 0;
		std::vector<int> primes{2};
		for (int curr=3; curr<n; curr+=2) {
			bool isPrime = true;
			for (int prime : primes) {
				if (prime * prime > curr) break;
				else if (curr % prime == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) primes.push_back(curr);
		}
		return primes.size();
	}
};
