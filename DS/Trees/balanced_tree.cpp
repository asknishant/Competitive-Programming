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

class HeightBalancedPair {
  public: 
    int height;
    bool isBalanced;
};

HeightBalancedPair checkBalance(node* root) {
  HeightBalancedPair HBPair;
  if(root == NULL) {
    HBPair.height = 0;
    HBPair.isBalanced = true;
    return HBPair;
  }
  //Recursive
  //Post order.

  HeightBalancedPair left = checkBalance(root->left);
  HeightBalancedPair right = checkBalance(root->right);

  HBPair.height = max(left.height,right.height) + 1;

  if(abs(left.height - right.height) <= 1 and left.isBalanced and right.isBalanced) {
    HBPair.isBalanced = true;
  } else {
    HBPair.isBalanced = false;
  }
  return HBPair;
}
int main() {
  node* root = buildTree();
   printTree(root); 
  cout << endl;
  if(checkBalance(root).isBalanced) {
    cout << "Balanced Tree";
  } else {
    cout << "Not Balanced Tree";
  }
  return 0;
}
