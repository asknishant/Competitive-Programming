int KthSmallestElement(Node *root, int k)
{
	//add code here.
	if (root == NULL)
	{
		return -1;
	}
	Node *curr, *pre;
	curr = root;
	while (curr != NULL)
	{
		if (curr->left == NULL)
		{
			k--;
			if (k == 0)
			{
				return curr->data;
			}
			curr = curr->right;
		}
		else
		{
			pre = curr->left;
			while (pre->right != NULL && pre->right != curr)
			{
				pre = pre->right;
			}
			if (pre->right == NULL)
			{
				pre->right = curr;
				curr = curr->left;
			}
			else
			{
				pre->right = NULL;
				k--;
				if (k == 0)
				{
					return curr->data;
				}
				curr = curr->right;
			}
		}
	}
	return -1;
}
