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
		TreeNode* curr = root;
		while (curr != p) {
			p_stack.push(curr);
			curr = p->val < curr->val ? curr->left : curr->right;
		}
		p_stack.push(p);

		curr = root;
		while (curr != q) {
			q_stack.push(curr);
			curr = q->val < curr->val ? curr->left : curr->right;
		}
		q_stack.push(q);

		auto& lo = p_stack.size() < q_stack.size() ? p_stack : q_stack;
		auto& hi = p_stack.size() < q_stack.size() ? q_stack : p_stack;
		while (hi.size() > lo.size()) hi.pop();
		while (lo.top() != hi.top()) {
			lo.pop();
			hi.pop();
		}
		return lo.top();
	}
};
