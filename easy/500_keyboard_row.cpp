class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        auto const toUpper = [](char c) {
            return c - 'a' + 'A';
        };
        auto const test = [](string const& word, set<char> const& row) {
            return std::all_of(word.begin(), word.end(),
                   [&row](char c) { return row.find(c) != row.end(); });
        };
        string const topRow{"qwertyuiop"};
        string const secondRow{"asdfghjkl"};
        string const thirdRow{"zxcvbnm"};
        vector<string> ret{};
        vector<set<char>> rowSets {
            std::set<char>(topRow.begin(), topRow.end()),
            std::set<char>(secondRow.begin(), secondRow.end()),
            std::set<char>(thirdRow.begin(), thirdRow.end()),
        };
        for (auto& rowSet : rowSets)
        {
            for (char c : rowSet)
            {
                rowSet.insert(toUpper(c));
            }
        }
        for (string const& word : words)
        {
            if (std::any_of(rowSets.begin(), rowSets.end(),
                            [&word, &test](std::set<char> const& row) { 
                                return test(word, row);
                            }))
            {
                ret.push_back(word);
            }
        }
        return ret;
    }
};
