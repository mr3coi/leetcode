class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // NOTE: All left shift outputs can be obtained using right shifts and vice versa,
    //       so we can assume left shift only.
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[0] == goal[i])
            {
                bool isMatch{true};
                for (int j = 1; j < s.size(); ++j)
                {
                    auto mappedIdx{i + j >= s.size() ? i + j - s.size() : i + j};
                    if (s[j] != goal[mappedIdx])
                    {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
