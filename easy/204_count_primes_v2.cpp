/* Only keep count of primes, and check if a
 * number is prime from scratch to save memory
 * - Time:  O(n^1.5)
 * - Space: O(1)
 */
class Solution {
public:
	int isPrime(int n) {
		if (n % 2 == 0) return 0;
		int divisor = 3;
		while (divisor * divisor <= n) {
			if (n % divisor == 0) return 0;
			divisor += 2;
		}
		return 1;
	}

	int countPrimes(int n) {
		if (n <= 2) return 0;
		int count = 1;
		for (int curr=3; curr<n; curr+=2) {
			count += isPrime(curr);
		}
		return count;
	}
};
