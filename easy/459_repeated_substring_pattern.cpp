class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        auto const len = s.length();
        for (int i=1; i <= len / 2; ++i)
        {
            if (len % i == 0)
            {
                bool ret{true};
                for (int j = 0; j < i; ++j)
                {
                    for (int k = 1; k < len / i; ++k)
                    {
                        if (s[j + i * k] != s[j])
                        {
                            ret = false;
                            break;
                        }
                    }
                    if (!ret)
                    {
                        break;
                    }
                }
                if (ret)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
