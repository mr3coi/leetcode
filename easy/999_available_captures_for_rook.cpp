#define BOARD_LEN 8

class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    inline bool locIsValid(int loc)
    {
        return loc >= 0 && loc < BOARD_LEN;
    }

    int numRookCaptures(vector<vector<char>>& board)
    {
        // Locate rook.
        int R, C;
        bool foundRook{false};
        for (R = 0; R < BOARD_LEN; ++R)
        {
            for (C = 0; C < BOARD_LEN; ++C)
            {
                if (board[R][C] == 'R')
                {
                    foundRook = true;
                    break;
                }
            }
            if (foundRook)
            {
                break;
            }
        }

        // Function to search along one direction.
        auto const search = [&](std::function<void(int&,int&)> update) -> int {
            int r = R;
            int c = C;
            update(r, c);
            while (locIsValid(r) && locIsValid(c))
            {
                if (board[r][c] == 'p')
                {
                    return 1;
                }
                else if (board[r][c] == 'B')
                {
                    return 0;
                }
                update(r, c);
            }
            return 0;
        };

        return search([](int& r, int& c) { ++r; })
             + search([](int& r, int& c) { ++c; })
             + search([](int& r, int& c) { --r; })
             + search([](int& r, int& c) { --c; });
    }
};
