class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(sqrt(candies/num_people^2) + num_people)
    //                  (first term could be negligible)
    // Space complexity: Theta(1)
    vector<int> distributeCandies(int candies, int const num_people)
    {
        std::vector<int> ret(num_people);
        int nbRounds{};
        int nextRoundLen{num_people};
        // Calculate # of full rounds.
        while (candies >= nextRoundLen * (nextRoundLen + 1) / 2)
        {
            ++nbRounds;
            nextRoundLen = (nbRounds + 1) * num_people;
        }
        candies -= nbRounds * num_people * (nbRounds * num_people + 1) / 2;
        // Address each element.
        for (int i = 0; i < num_people; ++i)
        {
            ret[i] += nbRounds * (i + 1) + num_people * nbRounds * (nbRounds - 1) / 2;
            if (candies > 0)
            {
                int const add = std::min(candies, nbRounds * num_people + i + 1);
                candies -= add;
                ret[i] += add;
            }
        }
        return ret;
    }
};
