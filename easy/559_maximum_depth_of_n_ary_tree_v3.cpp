/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
    val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
 */
class Solution {
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    int maxDepth(Node* root) {
        if (!root)
        {
            return 0;
        }
        std::queue<std::pair<Node const*, int>> q;
        q.emplace(root, 1);
        int ret{};
        while (!q.empty())
        {
            auto const n = q.front();
            q.pop();
            ret = std::max(ret, n.second);
            for (auto const* child : n.first->children)
            {
                q.emplace(child, n.second + 1);
            }
        }
        return ret;
    }
};
