/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	 int val;
 *	 TreeNode *left;
 *	 TreeNode *right;
 *	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		std::stack<TreeNode*> p_stack, q_stack;

		p_stack.push(root);
		std::unordered_set<TreeNode*> visited;
		while (p_stack.top() != p) {
			visited.insert(p_stack.top());
			if (p_stack.top()->left and visited.find(p_stack.top()->left) == visited.end())
				p_stack.push(p_stack.top()->left);
			else if (p_stack.top()->right and visited.find(p_stack.top()->right) == visited.end())
				p_stack.push(p_stack.top()->right);
			else p_stack.pop();
		}
		p_stack.insert(p);

		q_stack.push(root);
		visited.clear();
		while (q_stack.top() != q) {
			visited.insert(q_stack.top());
			if (q_stack.top()->left and visited.find(q_stack.top()->left) == visited.end())
				q_stack.push(q_stack.top()->left);
			else if (q_stack.top()->right and visited.find(q_stack.top()->right) == visited.end())
				q_stack.push(q_stack.top()->right);
			else q_stack.pop();
		}
		q_stack.insert(q);

		auto& lo = p_stack.size() > q_stack.size() ? p_stack : q_stack;
		auto& hi = p_stack.size() > q_stack.size() ? q_stack : p_stack;
		while (lo.size() > hi.size()) lo.pop();
		while (lo.top()->val != hi.top()->val) {
			lo.pop();
			hi.pop();
		}
		return lo.top();
	}
};
