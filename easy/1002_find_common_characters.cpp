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

    // Time complexity: O(words.size() * max(word.size()))
    // Space complexity: Theta(words.size())
    vector<string> commonChars(vector<string>& words)
    {
        std::vector<std::vector<int>> counts(
                ALPHABET_SIZE, std::vector<int>(words.size()));
        for (int i = 0; i < words.size(); ++i)
        {
            auto const& word = words[i];
            for (auto const c : word)
            {
                ++counts[c - 'a'][i];
            }
        }

        std::vector<string> ret{};
        for (int c = 0; c < ALPHABET_SIZE; ++c)
        {
            int nbRepeats = *std::min_element(counts[c].begin(), counts[c].end());
            for (int i = 0; i < nbRepeats; ++i)
            {
                ret.emplace_back(1, static_cast<char>(c + 'a'));
            }
        }
        return ret;
    }
};
