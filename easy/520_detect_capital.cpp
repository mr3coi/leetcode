class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool detectCapitalUse(string word) {
        if (word.size() == 1)
        {
            return true;
        }
        auto isCapital = [](char c) { return c <= 'Z'; };
        if (isCapital(word[0]))
        {
            if (isCapital(word[1]))
            {
                return std::all_of(word.begin()+2, word.end(), isCapital);
            }
            else
            {
                return !std::any_of(word.begin()+2, word.end(), isCapital);
            }
        }
        else
        {
            return !std::any_of(word.begin()+1, word.end(), isCapital);
        }
        return true; // Should not reach here.
    }
};
