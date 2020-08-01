#include <bits/stdc++.h>
using namespace std;

class node {
  public:
  int data;
  node* left;
  node* right;

  node(int data) {
    this->data = data;
  }
};


node* buildTree() {
  int d;
  cin >> d;
  
  if(d ==-1) {
    return NULL;
  }
  node* n = new node(d);
  n->left = buildTree();
  n->right = buildTree();

  return n;
}

void printTree(node* root) {
  if(root ==NULL) {
    return;
  }

  //Printing pre order
  cout << root->data << " ";
  printTree(root->left);
  printTree(root->right);

}


//Assumption - All keys are unique and both a and b are present in the tree.
node* lca(node* root, int a, int b) {

  if(root == NULL) {
    return NULL;
  }
  if(root->data == a or root->data == b){
    return root;
  }
  node* leftans = lca(root->left,a, b);
  node* rightans = lca(root->right,a,b);

  if(leftans != NULL and rightans != NULL) {
    return root;
  }
  if(leftans!=NULL){
    return leftans;
  }
  return rightans;

}

int main() {

  
  node* root = buildTree();
   printTree(root); 
  cout << endl;
  int a, b;
  cin >> a >> b;
   cout << lca(root, a, b)->data;
  return 0;
}
