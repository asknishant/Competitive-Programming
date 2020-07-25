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

void printInorderTree(node* root) {

	if(root == NULL) {
		return;
	}


	printInorderTree(root->left);
	cout << root->data << " ";
	printInorderTree(root->right);

}

void printPreorderTree(node* root) {

	if(root == NULL) {
		return;
	}

	cout << root->data << " ";
	printPreorderTree(root->left);
	printPreorderTree(root->right);

}

void printPostorderTree(node* root) {

	if(root == NULL) {
		return;
	}

	printPostorderTree(root->left);
	printPostorderTree(root->right);
	cout << root->data << " ";

}


int main() {

	node * root = buildTree();
	printInorderTree(root);
	cout << endl;
	printPreorderTree(root);
	cout << endl;
	printPostorderTree(root);
	
	return 0;
}
