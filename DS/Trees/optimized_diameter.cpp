/*
              8
            /  \
          10    3
         / \     \
        1   6     14
           / \    /
          9   7  13

          input->8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
*/


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
  node* n = new node(d);
  if(d == -1) {
    return NULL;
  }
  n->left = buildTree();
  n->right = buildTree();

  return n;
}

int height(node* root) {
  if(root == NULL) {
    return 0;
  }
  int leftSubtree = height(root->left);
  int rightSubtree = height(root->right);

  return max(leftSubtree, rightSubtree) + 1;
}
void printTree(node* root) {
  if(root == NULL) {
    return;
  }

  cout << root->data << " ";
  printTree(root->left);
  printTree(root->right); 
}

void printKthLevel(node* root, int k) {
  if(root == NULL) {
    return;
  }
  if(k == 0)  return;
  if(k == 1) {
    cout << root->data << " ";
  }
  printKthLevel(root->left, k-1);
  printKthLevel(root->right, k-1);

}

void printAllLevels(node* root) {
  int H = height(root);

  for(int i=0;i<H;i++) {
    printKthLevel(root, i);
    cout << endl;
  }
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

int countNodes(node* root) {
  if(root == NULL) {
    return 0;
  }
  return countNodes(root->left) + countNodes(root->right) + 1; 
}

int countData(node* root) {
  if(root == NULL) {
    return 0;
  }
  return countData(root->left) + countData(root->right) + root->data;
}

int diameter(node* root) {

  if(root == NULL) {
    return 0;
  }
  int h1 = height(root->left);  //height of left subtree
  int h2 = height(root->right); //height of right subtree
  int op1 = h1 + h2;  //Height of particular node
  int op2 = diameter(root->left);
  int op3 = diameter(root->right);

  return max(op1 + 1,max(op2,op3));
}

//Optimized diameter O(N).
class Pair {
  public:
    int diameter;
    int height;
};

Pair fastDiameter(node* root) {
  Pair p;
  if(root==NULL) {
    p.height = p.diameter = 0;
    return p;
  }
  //Doing post order traversal
  Pair left = fastDiameter(root->left);
  Pair right = fastDiameter(root->right);

  p.height = max(left.height, right.height) + 1;
  p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));

  return p;
}
int  main() {

  node* root = buildTree();
  // printTree(root);
  // cout << endl << height(root) << endl;
  // printKthLevel(root, 3);

  // cout << endl;
  // printAllLevels(root);

  // cout << endl;
  // bfs(root);

  //cout << countNodes(root) << endl << countData(root);

  cout << diameter(root) << endl;
  Pair p = fastDiameter(root);
  cout << p.diameter << " is the diameter of tree with max height " << p.height; 
  return 0;
}
