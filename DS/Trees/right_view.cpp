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

void rightView(node* root, int level) {
  
  if(root == NULL) {
    return;
  }

  static int maxlevel = -1;
  if(level > maxlevel) {
    maxlevel = level;
    cout << root->data << " ";
  }
 
  rightView(root->right, level+1);
  rightView(root->left, level+1);

}


int main() {

  
  node* root = buildTree();
   printTree(root); 
  cout << endl;
  rightView(root, 0);

  return 0;
}
