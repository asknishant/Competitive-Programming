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

node* buildTreeGivenTraversals(int *in, int *pre, int start, int end) {
  if(start > end) {
    return NULL;
  }
  static int i=0;
  int index = -1;
  for(int j=start;j<=end;j++) {
    if(in[j] == pre[i]) {
      index = j;
      break;
    }
  }
  node* n = new node(pre[i]);
  i++;
  n->left = buildTreeGivenTraversals(in, pre, start, index-1);
  n->right = buildTreeGivenTraversals(in, pre, index+1, end);

  return n;
}
int main() {

  //Given in-order and pre-order traversals of the tree in forms of an array build a tree.Print it in either pre-order, in-order or post-order wise.(Here pre order wise).
  int pre[] = {1,2,3,4,8,5,6,7};
  int in[] = {3, 2, 8, 4, 1, 6 ,7 ,5};
  int n = sizeof(in)/sizeof(int); //Size of in and pre are the same.
  node* root = buildTreeGivenTraversals(in, pre, 0, n-1);
   printTree(root); 
  cout << endl;
  

  return 0;
}
