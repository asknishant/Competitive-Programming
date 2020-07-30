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

node* buildTreeFromArray(int *a, int start, int end) {

  if(start > end) {
    return NULL;
  }
  int mid = (start + end)/2;
  node* n = new node(a[mid]);
  n->left = buildTreeFromArray(a, start, mid-1);
  n->right = buildTreeFromArray(a, mid+1, end);

  return n;
}
int main() {

  int a[] = {1,2,3,4,5,6,7};
  int n = sizeof(a)/sizeof(int);
  node* root = buildTreeFromArray(a, 0, n-1);
   printTree(root); 
  cout << endl;
  

  return 0;
}
