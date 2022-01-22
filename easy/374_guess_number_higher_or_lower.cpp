/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 0, end = n;
        while (start + 1 < end)
        {
            auto mid = start + (end - start) / 2;
            auto res = guess(mid);
            if (res < 0)
            {
                end = mid;
            }
            else if (res > 0)
            {
                start = mid;
            }
            else
            {
                return mid;
            }
        }
        return guess(start) == 0 ? start : end;
    }
};
