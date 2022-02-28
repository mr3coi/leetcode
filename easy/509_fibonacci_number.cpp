class Solution {
public:
    int fib(int n) {
        if (n <= 1)
        {
            return n;
        }
        std::vector<int> fibs(n+1);
        fibs.at(1) = 1;
        for (int i = 2; i <= n; ++i)
        {
            fibs.at(i) = fibs.at(i-1) + fibs.at(i-2);
        }
        return *fibs.rbegin();
    }
};
