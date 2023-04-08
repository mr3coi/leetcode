class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    string defangIPaddr(string address)
    {
        std::string ret(address.size() + 6, ' ');
        int idx{static_cast<int>(ret.size()) - 1};
        for (auto it = address.rbegin(); it != address.rend(); ++it)
        {
            if (*it == '.')
            {
                ret[idx] = ']';
                ret[idx - 1] = '.';
                ret[idx - 2] = '[';
                idx -= 3;
            }
            else
            {
                ret[idx--] = *it;
            }
        }
        return ret;
    }
};
