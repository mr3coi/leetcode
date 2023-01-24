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

    char toChar(int i)
    {
        return static_cast<char>(i + 'a');
    }

    int toIdx(char c)
    {
        return static_cast<int>(c - 'a');
    }

    // Here "top" refers to the smallest element in a given equivalence set.
    // We do not need to track the whole equivalence sets; only the tops are
    // of interest.
    //
    // Time Complexity: Theta(len(s1) + len(baseStr))
    // Space Complexity: Theta(1)
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        std::vector<int> equivTops(ALPHABET_SIZE);
        // By default, each equivalence set is a singleton with the single element
        // as top..
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            equivTops[i] = i;
        }

        // Track the tops of equivalence sets.
        for (int i = 0; i < s1.size(); ++i)
        {
            auto const oldTop =
                std::max(equivTops[toIdx(s1[i])], equivTops[toIdx(s2[i])]);
            auto const newTop =
                std::min(equivTops[toIdx(s1[i])], equivTops[toIdx(s2[i])]);
            for (int j = 0; j < ALPHABET_SIZE; ++j)
            {
                // Overwrite the tops of all the elements in the equivalence set
                // that has `oldTop` as its top with `newTop`.
                // This makes sure that the whole equivalence set is kept updated.
                if (equivTops[j] == oldTop)
                {
                    equivTops[j] = newTop;
                }
            }
        }

        // Produce output using the equivalence sets.
        std::ostringstream o;
        for (char const c : baseStr)
        {
            // Choose the lexicographically smallest character in the set.
            o << toChar(equivTops[toIdx(c)]);
        }
        return o.str();
    }
};
