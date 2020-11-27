#include <bits/stdc++.h>
using namespace std;

class node {
	public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {
	int d;
	cin >> d;

	if(d == -1) {
		return NULL;
	}
	node* n = new node(d);
	
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void printTree(node* root) {

	if(root == NULL) {
		return;
	}

	cout << root->data << " ";
	printTree(root->left);
	printTree(root->right);

}
int main() {

	node * root = buildTree();
	printTree(root);
	return 0;
}
