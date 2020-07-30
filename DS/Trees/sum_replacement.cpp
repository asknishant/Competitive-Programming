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

void bfs(node* root) {
  queue<node*> q;
  q.push(root);

  while(!q.empty()) {
    node* f = q.front();
    cout << f->data << " ";
    q.pop();

    if(f->left) {
      q.push(f->left);
    }
    if(f->right) {
      q.push(f->right);
    }
  }
}

int sumReplacement(node* root) {
  if(root == NULL) {
    return 0;
  }
  if(root->left == NULL and root->right == NULL) {
    return root->data;
  }
  int leftSum = sumReplacement(root->left);
  int rightSum = sumReplacement(root->right);
  
  int temp = root->data;
  root->data = leftSum + rightSum;

  return temp + root->data;
}
int main() {
  node* root = buildTree();
   printTree(root);
   cout << endl;
   sumReplacement(root);
   printTree(root);
  cout << endl;
  bfs(root);
  return 0;
}
