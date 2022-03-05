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

    vector<int> preorder(Node* root) {
        std::vector<int> ret{};
        if (!root)
        {
            return ret;
        }
        std::stack<Node const*> s;
        s.push(root);
        while (!s.empty())
        {
            Node const* curr = s.top();
            s.pop();
            ret.push_back(curr->val);
            for (auto it = curr->children.rbegin(); it != curr->children.rend(); ++it)
            {
                if (*it)
                {
                    s.push(*it);
                }
            }
        }
        return ret;
    }
};
