using Dict = std::unordered_map<char,char>;

class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    Dict buildAlienDic(std::string const& dic)
    {
        Dict d;
        for (int i = 0; i < dic.size(); ++i)
        {
            d[dic[i]] = static_cast<char>('a' + i);
        }
        return d;
    }

    // Time complexity: O(words.size() * maxWordLen)
    // Space complexity: Theta(1)
    bool isAlienSorted(vector<string>& words, string const& order)
    {
        if (words.size() <= 1)
        {
            return true;
        }
        Dict d = buildAlienDic(order);
        for (auto& word : words)
        {
            // Translate each word.
            // Does not preserve the input data.
            for (int i = 0; i < word.size(); ++i)
            {
                word[i] = d[word[i]];
            }
        }
        // Compare translated words.
        for (int i = 1; i < words.size(); ++i)
        {
            if (words[i] > words[i-1])
            {
                return false;
            }
        }
        return true;
    }
};
