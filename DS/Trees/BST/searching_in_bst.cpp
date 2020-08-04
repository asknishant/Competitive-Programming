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


//Accepts the old root node and data and returns a new node.
node* insertInBST(int d,node* root) {
  if(root == NULL) {
    return new node(d);
  }
  if(d>=root->data) {
    root->right = insertInBST(d, root->right);
  }
  else if(d < root->data){
    root->left = insertInBST(d, root->left);
  }
  return root;
}

node* build() {
  int d;
  cin >> d;
  node* root = NULL;
  while(d!=-1){
    root = insertInBST(d, root);
    cin >> d;
  }
  return root;
}

//level order
void bfs(node* root) {
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()) {
    node* f = q.front();
    if(f == NULL) {
      cout << endl;
      q.pop();
      if(!q.empty()) {
        q.push(NULL);
      }
    }
    else {
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
}

//Inorder print
void inOrder (node* root) {
  if( root == NULL) {
    return;
  }
 
  inOrder(root->left);
   cout << root->data;
  inOrder(root->right);
}

bool search(node* root, int data) {
  if(root == NULL) {
    return false;
  }
  if(root->data == data) {
    return true;
  }
  if(root->data <= data) {
    search(root->right, data);
  } else {
    search(root->left , data);
  }
}
int main() {
  node* root = build();
  int x;  cin >> x;
  if(search(root, x)) {
    cout << "YES present";
  } else {
    cout << "NO not present";
  }
  return 0;
}
