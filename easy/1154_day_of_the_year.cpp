class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool isLeapYear(int const year)
    {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    int dayOfYear(string date)
    {
        std::array<int, 13> const daysPerMonth = {
            -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
        int const year{stoi(date.substr(0, 4))};
        int const month{stoi(date.substr(5, 2))};
        int const day{stoi(date.substr(8, 2))};
        int ret{day};
        for (int m = 1; m < month; ++m)
        {
            ret += daysPerMonth[m];
        }
        ret += (month > 2 && isLeapYear(year));
        return ret;
    }
};
