class RecentCounter
{
    std::queue<int> q{};

public:
    RecentCounter()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    
    int ping(int t)
    {
        update(t);
        return q.size();
    }

    // Remove all outdated requests and add the latest request.
    void update(int t)
    {
        while (!q.empty() && q.front() < t - 3000)
        {
            q.pop();
        }
        q.push(t);
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
