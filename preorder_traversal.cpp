//Preorder traversal using stack
//https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45559/My-Accepted-code-with-explaination.-Does-anyone-have-a-better-idea

void preorder_traversal_iteratively(TreeNode* root)
{
	if (root == 0)
		return;
	stack<TreeNode*> s;
	s.push(root);
	cout << root->val << ' '; // visit root
	TreeNode* last_pop = root;
	while (!s.empty())
	{
		TreeNode* top = s.top();
		if (top->left != 0 && top->left != last_pop && top->right != last_pop) // push_left
		{
			s.push(top->left);
			cout << top->left->val << ' '; // visit top->left
		}
		else if (top->right != 0 && top->right != last_pop && (top->left == 0 || top->left == last_pop)) // push_right
		{
			s.push(top->right);
			cout << top->right->val << ' '; // visit top->right
		}
		else // pop
		{
			s.pop();
			last_pop = top;
		}
	}
}
