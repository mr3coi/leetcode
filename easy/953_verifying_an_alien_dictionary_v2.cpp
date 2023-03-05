// Variant of std::less where the translated versions are compared.
class AlienLess
{
    using Dict = std::unordered_map<char,char>;

public:
    AlienLess(std::string const& alphabet)
    : d{buildAlienDic(alphabet)}
    {
    }

    bool operator()(std::string const& lhs, std::string const& rhs)
    {
        auto l = lhs.begin();
        auto r = rhs.begin();
        while (l != lhs.end() && r != rhs.end())
        {
            if (d.at(*l) < d.at(*r))
            {
                return true;
            }
            if (d.at(*l) > d.at(*r))
            {
                return false;
            }
            ++l;
            ++r;
        }
        // Exclude the case where lhs == rhs since this is a less op.
        return l == lhs.end() && r != rhs.end();
    }

    // Map each letter in the alien alphabet to its index.
    // Use a-z instead of 0-25 to save space.
    Dict buildAlienDic(std::string const& dic)
    {
        Dict d;
        for (int i = 0; i < dic.size(); ++i)
        {
            d[dic[i]] = static_cast<char>('a' + i);
        }
        return d;
    }
private:
    Dict d;
};

class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(words.size() * maxWordLen)
    // Space complexity: Theta(1)
    bool isAlienSorted(vector<string>& words, string const& order)
    {
        if (words.size() <= 1)
        {
            return true;
        }
        AlienLess less{order};

        // Compare translated words.
        for (int i = 1; i < words.size(); ++i)
        {
            if (less(words[i], words[i-1]))
            {
                return false;
            }
        }
        return true;
    }
};
