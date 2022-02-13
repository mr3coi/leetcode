class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        auto const toUpper = [](char c) {
            return (c >= 'a' ? c - 'a' + 'A' : c);
        };
        stack<char> st;
        for (char c : s)
        {
            if (c != '-')
            {
                st.push(toUpper(c));
            }
        }
        vector<char> outReverse;
        outReverse.reserve(st.size() + st.size() / k);
        int counter{};
        while (!st.empty())
        {
            char c = st.top();
            st.pop();
            outReverse.push_back(c);
            if (++counter == k && !st.empty())
            {
                outReverse.push_back('-');
                counter = 0;
            }
        }
        return std::string(outReverse.rbegin(), outReverse.rend());
    }
};
