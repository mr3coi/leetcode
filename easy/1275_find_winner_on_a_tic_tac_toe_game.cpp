#define MAX_NB_MOVES 9
#define TTT_NB_COLS 3

class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    // Time complexity: O(1)
    bool hasWon(std::vector<int>& moves)
    {
        if (moves.size() < 3)
        {
            return false;
        }
        std::sort(moves.begin(), moves.end());
        bool match{false};
        for (int i = 0; i < moves.size() - 2; ++i)
        {
            for (int j = i + 1; j < moves.size() - 1; ++j)
            {
                for (int k = j + 1; k < moves.size(); ++k)
                {
                    if (moves[j] - moves[i] == moves[k] - moves[j])
                    {
                        switch (moves[j] - moves[i])
                        {
                        case 1: match = moves[i] % TTT_NB_COLS == 0; break;
                        case 2: match = moves[i] == 2; break;
                        case 3: match = true; break;
                        case 4: match = moves[i] == 0; break;
                        }
                        if (match)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    string tictactoe(vector<vector<int>> const& moves)
    {
        if (moves.size() < 5)
        {
            return "Pending";
        }
        std::vector<int> aMoves{};
        std::vector<int> bMoves{};
        for (int i = 0; i < moves.size(); ++i)
        {
            auto const& move = moves[i];
            auto& m = i & 1 ? bMoves : aMoves;
            m.push_back(move[0] * TTT_NB_COLS + move[1]);
        }
        if (hasWon(aMoves))
        {
            return "A";
        }
        else if (hasWon(bMoves))
        {
            return "B";
        }
        else if (moves.size() == MAX_NB_MOVES)
        {
            return "Draw";
        }
        else
        {
            return "Pending";
        }
        return "FAIL"; // Shouldn't reach here.
    }
};
