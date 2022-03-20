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
        int ret{};
        for (Node* child : root->children)
        {
            ret = std::max(ret, maxDepth(child));
        }
        return ret + 1;
    }
};
