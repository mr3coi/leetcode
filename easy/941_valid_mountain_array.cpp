class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    bool validMountainArray(vector<int>& arr)
    {
        bool decreasing{false};

        // Edge case: Mountain width & left end
        if (arr.size() < 3 || arr[1] <= arr[0])
        {
            return false;
        }

        int last{arr[0]};
        for (int i = 1; i < arr.size(); ++i)
        {
            auto const& curr = arr[i];
            if (curr == last)
            {
                // Has to be strict.
                return false;
            }
            // Recognize the first decreasing point.
            if (curr < last && !decreasing)
            {
                decreasing = true;
            }
            if (decreasing != (curr < last))
            {
                return false;
            }
            last = curr;
        }
        // Edge case: Right end
        // Should have decreased at least once before
        // reaching the end.
        return decreasing;
    }
};
