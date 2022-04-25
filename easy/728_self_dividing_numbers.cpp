class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> ret{};
        auto const helper = [](int num)
        {
            int copy{num};
            while (copy)
            {
                int digit = copy % 10;
                if (!digit || num % digit)
                {
                    return false;
                }
                copy /= 10;
            }
            return true;
        };
        for (int num = left; num <= right; ++num)
        {
            if (helper(num))
            {
                ret.push_back(num);
            }
        }
        return ret;
    }
};
