class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(s.size())
    // Space complexity: O(s.size())
    string removeDuplicates(string const& s)
    {
        std::stack<char> st{};
        for (char c : s)
        {
            if (st.empty() || st.top() != c)
            {
                st.push(c);
            }
            else
            {
                st.pop();
            }
        }
        std::ostringstream o;
        while (!st.empty())
        {
            o << st.top();
            st.pop();
        }
        auto ret = o.str();
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
