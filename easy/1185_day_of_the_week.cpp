class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    static bool isLeapYear(int const year)
    {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    static string dayOfTheWeek(int const day, int const month, int const year)
    {
        // Dec. 31st, 1970 is a Thursday.
        int nbDays{day + 4};
        for (int y = 1971; y < year; ++y)
        {
            nbDays += 365 + isLeapYear(y);
        }
        for (int m = 1; m < month; ++m)
        {
            nbDays += daysPerMonth[m];
        }
        nbDays += (month > 2 && isLeapYear(year));
        nbDays %= 7;
        return dayOfWeek[nbDays];
    }

private:
    static std::array<std::string, 7> const dayOfWeek;
    static std::array<int, 13> const daysPerMonth;
};

std::array<std::string, 7> const Solution::dayOfWeek = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

std::array<int, 13> const Solution::daysPerMonth = {
    -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
