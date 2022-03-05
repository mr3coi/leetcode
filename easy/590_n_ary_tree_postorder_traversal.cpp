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

    vector<int> postorder(Node* root) {
        std::vector<int> ret{};
        if (!root)
        {
            return ret;
        }
        std::stack<Node const*> s1;
        std::stack<Node const*> s2;
        s1.push(root);
        while (!s1.empty())
        {
            Node const* curr = s1.top();
            s1.pop();
            s2.push(curr);
            for (Node const* child : curr->children)
            {
                if (child)
                {
                    s1.push(child);
                }
            }
        }
        while (!s2.empty())
        {
            auto const* curr = s2.top();
            s2.pop();
            ret.push_back(curr->val);
        }
        return ret;
    }
};
