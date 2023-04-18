#define ALPHABET_SIZE 26

class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    std::vector<int> breakdown(std::string const& chars)
    {
        std::vector<int> counts(ALPHABET_SIZE);
        for (char const c : chars)
        {
            ++counts[static_cast<int>(c - 'a')];
        }
        return counts;
    }

    bool covers(std::vector<int> const& supply, std::vector<int> const& demand)
    {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            if (demand[i] > supply[i])
            {
                return false;
            }
        }
        return true;
    }

    int countCharacters(vector<string> const& words, string const& chars)
    {
        auto const resource = breakdown(chars);
        int ret{};
        for (auto const& word : words)
        {
            auto const required = breakdown(word);
            ret += covers(resource, required) * static_cast<int>(word.size());
        }
        return ret;
    }
};
