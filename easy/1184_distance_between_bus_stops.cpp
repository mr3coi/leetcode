class Solution
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int distanceBetweenBusStops(vector<int> const& distance,
            int start, int destination)
    {
        int const s = std::min(start, destination);
        int const d = std::max(start, destination);
        int const totalSum
            = std::accumulate(distance.begin(), distance.end(), 0);
        int const clockWiseDist = std::accumulate(
                distance.begin() + s, distance.begin() + d, 0);
        return std::min(clockWiseDist, totalSum - clockWiseDist);
    }
};
