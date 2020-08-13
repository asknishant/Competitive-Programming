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

node* deleteInBST(node* root, int data) {
  if(root == NULL) {
    return NULL;
  } else if(data < root->data) {
    root->left = deleteInBST(root->left, data);
    return root;
  } else if(data == root->data) {
    //1.ifNode with zero children
    if(root->left == NULL and root->right == NULL) {
      delete root;
      return NULL;
    }
    //2. Only one child
    if(root->left != NULL and root->right == NULL) {
      node* temp = root->left;
      delete root;
      return temp;
    }
    if(root->right != NULL and root->left == NULL) {
      node* temp = root->right;
      delete root;
      return temp;
    }

    //3.Both the children are present.
    node* replace = root->right;
    //Finding inorder successor.
    while(replace->left != NULL) {
      replace = replace->left;
    }

    root->data = replace->data;
    root->right = deleteInBST(root->right, replace->data);
    return root;
    
  } else {
    root->right = deleteInBST(root->right, data);
    return root;
  }
}

//Check whether a tree is BST or not
bool isBST(node* root, int minV = INT_MIN, int maxV = INT_MAX) {
  if(root == NULL) {
    return true;
  }
  if(root->data >= minV and root->data <= maxV and isBST(root->left, minV, root->data) and isBST(root->right, root->data, maxV)) {
    return true;
  }
  return false;
}


int main() {
  node* root = build();
  inOrder(root);
  cout << endl;


  int s;  cin >> s;

  if(isBST(root)) {
    cout << "Tree is BST";
  } else {
    cout << "Not a BST";
  }
  return 0;
}
