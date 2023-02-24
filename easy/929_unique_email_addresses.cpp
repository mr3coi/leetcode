using Domain = std::string;
using Local = std::string;
using AddrPair = std::pair<Local, Domain>;

class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    AddrPair parseAddr(std::string const& rawAddr)
    {
        auto const delimLoc = rawAddr.find('@');
        auto const local = rawAddr.substr(0, delimLoc);
        auto const localNoPlus = local.substr(0, local.find('+'));
        localNoPlus.erase(remove(localNoPlus.begin(), localNoPlus.end(), '.'), localNoPlus.end());
        return {localNoPlus, rawAddr.substr(delimLoc+1, rawAddr.size())};
    }

    int numUniqueEmails(vector<string>& emails)
    {
        std::unordered_map<Domain, std::unordered_set<Local>> parsedAddrs;
        for (auto const& email : emails)
        {
            Local l;
            Domain d;
            std::tie(l, d) = parseAddr(email);
            parsedAddrs[d].insert(l);
        }
        int ret{};
        for (auto const& pair : parsedAddrs)
        {
            // Count # of unique local names per domain.
            ret += pair.second.size();
        }
        return ret;
    }
};
