class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::vector<std::string> ret{};
        int leastSum{std::numeric_limits<int>::max()};
        for (int i = 0; i < list1.size(); ++i)
        {
            auto const& rest = list1.at(i);
            auto const it = std::find(list2.begin(), list2.end(), rest);
            if (it != list2.end())
            {
                int const idxSum = i + it - list2.begin();
                if (idxSum < leastSum)
                {
                    ret.clear();
                    ret.push_back(rest);
                    leastSum = idxSum;
                }
                else if (idxSum == leastSum)
                {
                    ret.push_back(rest);
                }
            }
        }
        return ret;
    }
};
