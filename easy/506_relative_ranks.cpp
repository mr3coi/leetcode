class Solution {
public:
    // (pos, val, rank)
    using Record = std::tuple<int, int, int>;

    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    struct PosAsc
    {
        bool operator() (Record const& a, Record const& b)
        {
            return std::get<0>(a) < std::get<0>(b);
        }
    } posAsc;

    struct ScoreDesc
    {
        bool operator() (Record const& a, Record const& b)
        {
            return std::get<1>(a) > std::get<1>(b);
        }
    } scoreDesc;

    vector<string> findRelativeRanks(vector<int>& score) {
        auto translate = [](int rank) -> std::string {
            switch (rank)
            {
            case 1: return "Gold Medal";
            case 2: return "Silver Medal";
            case 3: return "Bronze Medal";
            default: return std::to_string(rank);
            }
            return "FAIL";
        };

        std::vector<Record> ds{};
        for (int i = 0; i < score.size(); ++i)
        {
            // Dummy rank -1 for now.
            ds.emplace_back(i, score.at(i), -1);
        }
        // First sort by score and fill in rank info.
        sort(ds.begin(), ds.end(), scoreDesc);
        for (int i=0; i<score.size(); ++i)
        {
            std::get<2>(ds.at(i)) = i + 1;
        }
        // Then sort by original position.
        sort(ds.begin(), ds.end(), posAsc);
        
        // Encode rank to generate output.
        std::vector<std::string> ret{};
        ret.reserve(score.size());
        std::transform(ds.begin(), ds.end(), std::back_inserter(ret),
            [&translate](Record const& r) { return translate(std::get<2>(r)); });
        return ret;
    }
};
