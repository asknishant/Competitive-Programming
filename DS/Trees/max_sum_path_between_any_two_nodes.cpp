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

class Pair{
  public:
    int maxSum;
    int branchSum;
  Pair() {
    branchSum = 0;
    maxSum = 0;
  }
};

Pair maxSumPath(node* root) {
  Pair p;
  if(root == NULL) {
    return p;
  }
  Pair ls = maxSumPath(root->left);
  Pair rs = maxSumPath(root->right);

  int op1 = root->data;
  int op2 = ls.branchSum + root->data;
  int op3 = rs.branchSum + root->data;
  int op4 = ls.branchSum + rs.branchSum + root->data;

  int curr_max_through_root = max(op1,max(op2,max(op3,op4)));
  p.branchSum = max(ls.branchSum,max(rs.branchSum,0)) + root->data;
  p.maxSum = max(ls.maxSum,max(rs.maxSum, curr_max_through_root));

  return p;
}
int main() {

  
  node* root = buildTree();
   printTree(root); 
  cout << endl;
   cout << maxSumPath(root).maxSum;


  return 0;
}
