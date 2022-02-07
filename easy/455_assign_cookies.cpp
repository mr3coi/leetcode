class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), std::greater<int>());
        sort(s.begin(), s.end(), std::greater<int>());
        auto gIt = g.begin();
        auto sIt = s.begin();
        int nbContent{};
        while (gIt != g.end() && sIt != s.end())
        {
            if (*gIt <= *sIt)
            {
                ++nbContent;
                ++sIt;
            }
            ++gIt;
        }
        return nbContent;
    }
};
