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
        std::vector<int> childDepths{};
        childDepths.reserve(root->children.size());
        std::transform(root->children.begin(), root->children.end(),
            std::back_inserter(childDepths),
            [&](Node* const child) { return maxDepth(child); });
        return (childDepths.size() > 0 ? *std::max_element(childDepths.begin(), childDepths.end()) : 0) + 1;
    }
};
