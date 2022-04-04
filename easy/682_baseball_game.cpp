class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int calPoints(vector<string>& ops) {
        std::stack<int> records{};
        for (auto const& op : ops)
        {
            if (op.compare("+") == 0)
            {
                int lastItem = records.top();
                records.pop();
                int secondLastItem = records.top();
                records.push(lastItem);
                records.push(lastItem + secondLastItem);
            }
            else if (op.compare("D") == 0)
            {
                int newItem = records.top() * 2;
                records.push(newItem);
            }
            else if (op.compare("C") == 0)
            {
                records.pop();
            }
            else
            {
                records.push(std::stoi(op));
            }
        }
        int ret{0};
        while (!records.empty())
        {
            ret += records.top();
            records.pop();
        }
        return ret;
    }
};
