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

    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        std::vector<std::vector<int>*> eqMap(ALPHABET_SIZE, nullptr);
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            eqMap[i] = new std::vector<int>(1, i);
        }

        // Build the initial equivalence relation map.
        for (int i = 0; i < s1.length(); ++i)
        {
            // Skip if two same characters are mapped as equivalent.
            if (s1[i] == s2[i])
            {
                continue;
            }
            auto*& c1Equiv = eqMap[toIdx(s1[i])];
            auto*& c2Equiv = eqMap[toIdx(s2[i])];
            // Skip if two characters already belong in the same equivalence set.
            if (c1Equiv == c2Equiv)
            {
                continue;
            }
            // Take the union of the two equivalence sets into one set 
            // and delete the other set.
            c2Equiv->insert(c2Equiv->end(), c1Equiv->begin(), c1Equiv->end());
            delete c1Equiv;
            // Make sure all the elements in the resulting equivalence set are
            // mapped to that set.
            for (auto const i : *c2Equiv)
            {
                eqMap[i] = c2Equiv;
            }
        }

        // Sort the equivalence sets in ascending order.
        for (auto* const equiv : eqMap)
        {
            std::sort(equiv->begin(), equiv->end(), std::less());
        }

        // Produce output using the equivalence sets.
        std::ostringstream o;
        for (char const c : baseStr)
        {
            // Choose the lexicographically smallest character in the set.
            o << toChar(eqMap[toIdx(c)]->at(0));
        }

        return o.str();
    }
};
