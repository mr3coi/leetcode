class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: Theta(n + trust.size())
    // Space complexity: Theta(n)
    int findJudge(int const n, vector<vector<int>>& trust)
    {
        std::vector<int> nbTrust(n, 0);
        std::vector<int> nbTrusted(n, 0);
        for (auto const& t : trust)
        {
            ++nbTrust[t[0]];
            ++nbTrusted[t[1]];
        }
        int nbCand{};
        int cand{-1};
        for (int i = 0; i < n; ++i)
        {
            if (nbTrusted[i] == n-1 && nbTrust[i] == 0)
            {
                ++nbCand;
                cand = i;
            }
        }
        return nbCand == 1 ? cand : -1;
    }
};
