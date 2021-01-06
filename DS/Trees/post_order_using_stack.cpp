//Post order traversal of a binary tree using stack.
//Tutorial - https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45559/My-Accepted-code-with-explaination.-Does-anyone-have-a-better-idea


void postorder_traversal_iteratively(TreeNode* root)
{
	if (root == 0)
		return;
	stack<TreeNode*> s;
	s.push(root);	
	TreeNode* last_pop = root;
	while (!s.empty())
	{		
		TreeNode* top = s.top();
		if (top->left != 0 && top->left != last_pop && top->right != last_pop) // push_left
		{
			s.push(top->left);
		}
		else if (top->right != 0 && top->right != last_pop && (top->left == 0 || top->left == last_pop)) // push_right
		{
			s.push(top->right);
		}
		else // pop
		{
			s.pop();
			last_pop = top;
			cout << top->val << ' '; // visit top
		}
	}
}
